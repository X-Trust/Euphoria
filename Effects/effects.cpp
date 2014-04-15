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

void Effects::genQueue(std::queue<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > >&q, MontageClip &mntg, bool tFlag){

    std::vector< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > funcs
    {
        {blur, "Blur" },
        {starburst, "starburst" },
        {rotateImage, "rotateImage"},
        {addImage, "addImage"},
        {diceCheck, "DiceCheck"},
        {addHat, "addHat"}
   };

    unsigned roll;
    if (tFlag) roll = funcs.size(); // THIS IS FOR TESTING
    else roll = mntg.dice() % globals::max_effect_number;
    for (unsigned i = 0; i < roll; ++i){
        if (tFlag) q.push(funcs[i]);  // THIS IS FOR TESTING
        else q.push(funcs[ mntg.dice() % funcs.size()]);
    }
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

bool Effects::starburst(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0) return true;
    al.min_frames = al.min_frames % 30;
    std::vector<Mat> spl;


    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        split(mntg._media[i]._frame, spl);                // process - extract only one channel
        for (unsigned i =0; i < 3; ++i){
            spl[al.min_frames % 3] = Mat::zeros( mntg._media[i]._frame.size(), spl[0].type());
        }
        merge(spl, mntg._media[i]._frame);
    }
    return true;
}

bool Effects::rotateImage(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0){ cout << " BROKE" << endl; return true;}
    int step, border, angle = 0;

    step = ((mntg.dice() % 9 + 1) * 360) / al.min_frames;
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

bool Effects::lensFlare( MontageClip &mntg, eff_args &al){
    return true;
}

bool Effects::addImage(MontageClip &mntg, eff_args &al){

    Mat new_image = cv::imread("F:\\projects\\C++\\Euphoria\\imgres.jpg");

    // select movement functions
    // have movement function act like effect function.
    // return a movement


    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

            //apply functions and image to frame
           // things that will do stuff

    }

    return true;
}

bool Effects::addHat(MontageClip &mntg, eff_args &al){

    Point p;
    Mat new_image = cv::imread("F:\\projects\\C++\\Euphoria\\imgres.jpg");
    int border = 500;

    cout << al.it << " THIS IS THE IT" << endl;
    for (unsigned i = al.it; i < al.it + al.min_frames and i < mntg._media.size(); i++){

        if( mntg._media[i]._faces.size() == 0 ){
            //No face found
            cout << "broke " << mntg._media[i]._faces.size() << endl;
            break;
        }

        for( auto facialROI: mntg._media[i]._faces){
             (p.x = facialROI.x);
            (p.y = facialROI.y);
            cout << "i " << i << std::endl ;
            cout << "total " << al.it + al.min_frames << "out of " <<  mntg._media.size() << std::endl;

            cv::Rect roi( p, new_image.size() );
            Mat dist = mntg._media[i]._frame( roi ) ;
            new_image.copyTo( dist, new_image );
        }
    }
    return true;
}


bool Effects::diceCheck(MontageClip &mntg, eff_args &al){

    for (unsigned i=0;i < 20; i++)
        cout << mntg.dice() << endl;
    return true;
}
