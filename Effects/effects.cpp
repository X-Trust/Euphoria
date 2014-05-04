#include "effects.h"
#include "Unit.hpp"
#include "MontageClip.hpp"
#include "form.hpp"
#include "Globals.h"

#include <tuple>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>

#include <QWidget>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define FRAME(i) mntg._media[i]._frame


using std::list;
using std::sqrt;
using std::pow;
using std::cout;
using std::endl;

using cv::Point;
using cv::Mat;
using cv::Size;

std::vector< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > >EffectFactory::funcs = {
//    {Effects::doNothing, "doNothing"},
//    {Effects::blur, "Blur" },
//    {Effects::starburst, "starburst" },
//    {Effects::rotateImage, "rotateImage"},
    {Effects::addHat, "addHat"},
//    {Effects::addText,"addText"},
//    {Effects::addImage, "addImage on Path" },
};

unsigned EffectFactory::getFCount(){

    return funcs.size();
}

std::function<bool(MontageClip&, eff_args&)> EffectFactory::makeEffect(int x) {
    if (x >= 0) {
        return funcs[x % funcs.size()].first;
    }
    else {
        return funcs[0].first;
    }
}

std::string EffectFactory::getFName(int x){
    return funcs[x % funcs.size()].second;
}

int getPt( int n1 , int n2 , float perc )
{
    int diff = n2 - n1;

    return n1 + ( diff * perc );
}

cv::Point calcPoint( cv::Point a, cv::Point b, cv::Point c, double location){

    int xa, xb;
    int ya, yb;

    xa = getPt( a.x , c.x, location);
    ya = getPt( a.y , c.y, location);
    xb = getPt( a.x , b.x ,location);
    yb = getPt( a.y , b.y ,location);

    // The Dot
    return cv::Point( getPt( xa , xb ,location), getPt( ya , yb ,location) );

}

void Effects::genQueue(std::queue<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > >&q, MontageClip &mntg, bool tFlag){

    std::vector< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > funcs
    {
        {doNothing, "doNothing"},
        {blur, "Blur" },
        {starburst, "starburst" },
        {rotateImage, "rotateImage"},
        {addHat, "addHat"},
 //       {addText,"addText"},
        {addImage, "addImage on Path" }
   };

    unsigned roll;
    if (tFlag) roll = funcs.size(); // THIS IS FOR TESTING
    else roll = mntg.dice() % globals::max_effect_number;
    for (unsigned i = 0; i < roll; ++i){
        if (tFlag) q.push(funcs[i]);  // THIS IS FOR TESTING
        else q.push(funcs[ mntg.dice() % funcs.size()]);
    }
}

bool Effects::doNothing(MontageClip &mntg, eff_args &al) {
    return true;
}

bool Effects::blur(MontageClip &mntg, eff_args &al){

    al.min_frames = al.min_frames % 50;
    al.size = al.size % 10;

    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        al.size++;
        cv::blur(mntg._media[i]._frame, mntg._media[i]._frame, Size(al.size, al.size));
    }
    return true;
}

bool Effects::starburst(MontageClip &mntg, eff_args &al){ // use/find better color algorithm

    // new algorithm should be able to pull each pixles color to a given RGB value

    if (al.min_frames == 0) return true;
    std::vector<Mat> spl;


    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        split(mntg._media[i]._frame, spl);                // process - extract only one channel
        for (unsigned i =0; i < 3; ++i){
            spl[mntg.dice() % 3] = Mat::zeros( mntg._media[i]._frame.size(), spl[0].type());
        }
        merge(spl, mntg._media[i]._frame);
    }
    return true;
}

bool Effects::rotateImage(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0){ cout << " BROKE" << endl; return true;}
    int step, border, angle = 0;

    step = ((mntg.dice() % 9 + 1) * 360) / al.min_frames;
    step *= (mntg.dice() % 2)? 1 : -1;
    border = mntg.frame_width - mntg.frame_height; // THIS CAN AND WILL BREAK!!!!! cell phone vids...

    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        copyMakeBorder(mntg._media[i]._frame,mntg._media[i]._frame,border,border,border,border,0,cv::Scalar(0,0,0));
        // can probably use this line of code to do some crazy stuff
        Mat matRotation = getRotationMatrix2D(Point(mntg._media[i]._frame.cols / 2, mntg._media[i]._frame.rows / 2), (angle - 180), 1);
        // Rotate the image
        warpAffine(mntg._media[i]._frame, matRotation, matRotation, mntg._media[i]._frame.size());
        mntg._media[i]._frame = Mat(matRotation, cv::Rect(border, border, mntg.frame_width , mntg.frame_height));
        angle += step;
    }

    return true;
}

bool Effects::addImage(MontageClip &mntg, eff_args &al){

    Mat new_image = cv::imread("F:\\projects\\C++\\Euphoria\\doge.jpg");

    // select movement functions
    // have movement function act like effect function.
    // return a movement
    std::vector<cv::Point> points;

    for( int i = 0 ; i < 10;i++){
        points.push_back( cv::Point(mntg.dice() % mntg.frame_width,
                                mntg.dice() % mntg.frame_height) );
    }

    double step = points.size() / (double)al.min_frames;
    double count = 0;

    int border = 500;
    int offset = border;
    cv::Point path_point;
    //fix this numbering

    for (unsigned j = al.it; j < al.it + al.min_frames and j < mntg._media.size();){


        for(unsigned i = 0 ; i < points.size() - 1 ; i++){
            cout << i << endl;

            for(count = 0 ; count <= 1, j < al.it + al.min_frames and j < mntg._media.size(); j++, count += step){

                for( auto it: points ){

                    cv::circle(  mntg._media[j]._frame, it, 10, cv::Scalar(0,255,255), 20, 8, 0);
                }
                cout << count << endl;
                if( count >= 1){ cout << "HAD TO BREAK" << endl;break;}

                path_point = calcPoint( points[i], points[i+1], points[ mntg.dice() % points.size() ], count);
                path_point.x += offset;
                path_point.y += offset;

                copyMakeBorder(mntg._media[j]._frame,mntg._media[j]._frame,border,border,border,border,0,cv::Scalar(0,0,0));
                new_image.copyTo( mntg._media[j]._frame(  cv::Rect( path_point, new_image.size() ) ), new_image );
                cv::circle( mntg._media[j]._frame, path_point, 4, cv::Scalar(255,0,255), 4, 8, 0);
                mntg._media[j]._frame = Mat(mntg._media[j]._frame, cv::Rect(border, border, mntg.frame_width , mntg.frame_height));
            }
        }
        return true;
    }
    return true;
}

bool Effects::addHat(MontageClip &mntg, eff_args &al){

    Point p;
    Mat new_image = cv::imread("F:\\projects\\C++\\Euphoria\\imgres.jpg");
    int border = 150;   // make this dynamic
    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        if( mntg._media[i]._faces.size() == 0 ){
            //No face found
            cout << "broke " << mntg._media[i]._faces.size() << endl;
            break;
        }

        for( auto facialROI: mntg._media[i]._faces){
            (p.x = facialROI.x+border);
            (p.y = facialROI.y - new_image.rows + (int)(facialROI.y * .5) + border);

            copyMakeBorder(mntg._media[i]._frame,mntg._media[i]._frame,border,border,border,border,0,cv::Scalar(0,0,0));
            cv::Rect roi( p, new_image.size() );
            Mat dist = mntg._media[i]._frame( roi ) ;
            new_image.copyTo( dist, new_image );

            mntg._media[i]._frame = Mat(mntg._media[i]._frame, cv::Rect(border, border, mntg.frame_width , mntg.frame_height));

        }
    }
    return true;
}

bool Effects::addText(MontageClip &mntg, eff_args &al){

    std::string text = "text";
    const char *font = "Times";

    CvFont something =  cv::fontQt(font);

    //Mat img(100, 500, CV_8UC3, cv::Scalar(0,0,0));

    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        addText( mntg._media[i]._frame, text, cv::Point(1,1), something );

       // cv::imshow("SADNESS", img);
      //  cv::waitKey(30);
    }

    return true;
}

bool Effects::lensFlare( MontageClip &mntg, eff_args &al){

    return true;
}

/*int getPt( int n1 , int n2 , float perc ){

    return n1 + ( n2 - n1 * perc );
}


cv::Point calcPoint( cv::Point a, cv::Point b, cv::Point c, double location){

    cv::Point E, F; // bad names


    E.x = a.x + ( location * (c.x - a.x));
    E.y = a.y + ( location * (c.y - a.y));

    F.x = a.x + ( location * (b.x - a.x));
    F.y = a.y + ( location * (b.y - a.y));

    E.x = E.x + ( location * (F.x - E.x));
    E.y = E.y + ( location * (F.y - E.x));
//    xa = getPt( a.x , c.x, location);
//    ya = getPt( a.y , c.y, location);
//    xb = getPt( a.x , b.x ,location);
//    yb = getPt( a.y , b.y ,location);

    // The point

    return a;

}

*/
