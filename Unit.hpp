#ifndef UNIT
#define UNIT

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include "Globals.h"
#include <array>
#include <iostream>

struct Attributes{
private:
   std::vector<cv::Rect> _faces;
public:
    Attributes() {}
    void detectFaces(cv::Mat &frame);
};

struct Unit {
private:
    std::array<cv::Mat, globals::clip_size> _frames;
    std::array<Attributes, globals::clip_size> _features ;

public:
    Unit() ;
    Unit(std::array<cv::Mat, globals::clip_size> frames);
    Unit(cv::VideoCapture &vid);
    int takeFrames(cv::VideoCapture &vid);
    void addAttributes();

    friend class MontageClip;
};

#endif // UNIT
