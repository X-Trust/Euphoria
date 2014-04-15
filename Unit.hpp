#ifndef UNIT
#define UNIT

#include "opencv2/core/core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>


#include "Globals.h"
#include <array>
#include <iostream>

/*
struct Unit {

    std::array<cv::Mat, globals::clip_size> _frames;
    std::array<Attributes, globals::clip_size> _features ;

    Unit() ;
    Unit(std::array<cv::Mat, globals::clip_size> frames);
    Unit(cv::VideoCapture &vid);

    int takeFrames(cv::VideoCapture &vid);
    void addAttributes();
    void transposeFrame( cv::Mat &image);
    friend class MontageClip;
};
*/
#endif // UNIT
