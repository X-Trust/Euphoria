#include "effects.h"
#include "Unit.hpp"
#include "MontageClip.hpp"
#include "form.hpp"
#include "Globals.h"

#include <list>
#include <iostream>
#include <functional>
#include <QWidget>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using std::list;
using cv::Point;
using cv::Mat;
using cv::Size;


void Effects::genQueue(std::queue<std::function<bool(MontageClip&,eff_args&)> >&q, MontageClip &mntg){

    std::vector< std::function<bool(MontageClip&,eff_args&)> > funcs{
      blur,
      starburst
    };
    unsigned roll = mntg.dice() % globals::max_effect_number ;
    for(unsigned i = 0; i < roll ; ++i ){

        q.push( funcs[ mntg.dice() % funcs.size()]);

    }

}

bool Effects::blur(MontageClip &mntg, eff_args &al){


    al.size = al.size % 10 ;
    for (; al.it != mntg._units.end() || al.min_frames <= 0; al.it++){

        if( al.it == mntg._units.end() ){return true;}

        for (Mat &frame : al.it->_frames) {

            if(al.min_frames-- <= 0){return true;}

            al.size++;
            cv::blur(frame, frame, Size(al.size, al.size));
        }
    }
    return true;
}

bool Effects::starburst(MontageClip &mntg, eff_args &al){

    std::vector<Mat> spl;

    for (; al.it != mntg._units.end(); al.it++){

        if( al.it == mntg._units.end() ){return true;}

        for (Mat &frame : al.it->_frames) {

            if(al.min_frames-- <= 0){return true;}

            split(frame, spl);                // process - extract only the correct channel
            for (int i =0; i < 3; ++i) {
                spl[al.min_frames % 3] = Mat::zeros(Size(frame.cols, frame.rows), spl[0].type());
            }
            merge(spl, frame);
        }
    }
    return true;
}

