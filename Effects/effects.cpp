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
        {diceCheck, "DiceCheck"}
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

    al.min_frames = al.min_frames % 30;
    al.size = al.size % 10;

    for (; al.it != mntg._units.end() || al.min_frames <= 0; al.it++){
        if (al.it == mntg._units.end()){return true;}
        for (Mat &frame : al.it->_frames){
            if (al.min_frames-- <= 0){return true;}

            al.size++;
            cv::blur(frame, frame, Size(al.size, al.size));
        }
    }
    return true;
}

bool Effects::starburst(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0) return true;
    al.min_frames = al.min_frames % 30;
    std::vector<Mat> spl;

    for (; al.it != mntg._units.end(); al.it++){
        for (Mat &frame : al.it->_frames){
            if (al.min_frames-- <= 0){return true;}

            split(frame, spl);                // process - extract only one channel
            for (int i =0; i < 3; ++i){
                spl[al.min_frames % 3] = Mat::zeros(Size(frame.cols, frame.rows), spl[0].type());
            }
            merge(spl, frame);
        }
    }
    return true;
}

bool Effects::rotateImage(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0) return true;
    int step, border, angle = 0;

    al.min_frames = al.min_frames % 100;
    step = ((mntg.dice() % 9 + 1) * 360) / al.min_frames;
    border = mntg.frame_width - mntg.frame_height; // THIS CAN AND WILL BREAK!!!!! cell phone vids...

    for (; al.it != mntg._units.end(); al.it++){
        for (Mat &frame : al.it->_frames){
            if (al.min_frames-- <= 0){return true;}

            copyMakeBorder(frame,frame,border,border,border,border,0,cv::Scalar(0,0,0));
            // can probably use this line of code to do some crazy stuff
            Mat matRotation = getRotationMatrix2D(Point(frame.cols / 2, frame.rows / 2), (angle - 180), 1);
            // Rotate the image
            warpAffine(frame, matRotation, matRotation, frame.size());
            frame = Mat(matRotation, cv::Rect(border, border, mntg.frame_width , mntg.frame_height));
            angle += step;
        }
    }
    return true;
}

bool Effects::lensFlare( MontageClip &mntg, eff_args &al){
    return true;
}

bool Effects::addImage(MontageClip &mntg, eff_args &al){

    if (al.min_frames == 0) return true;
    Mat new_image = cv::imread("F:\\projects\\C++\\Euphoria\\doge.jpg");

    // select movement functions
    // have movement function act like effect function.
    // return a movement

    for (; al.it != mntg._units.end(); al.it++){
        for (Mat &frame : al.it->_frames){
            if (al.min_frames-- <= 0){return true;}

            //apply functions and image to frame
           // things that will do stuff
        }
    }
    return true;
}

bool Effects::diceCheck(MontageClip &mntg, eff_args &al){

    for (int i=0;i < 20; i++)
        cout << mntg.dice() << endl;

}
