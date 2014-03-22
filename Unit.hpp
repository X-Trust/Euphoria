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
   std::vector<std::pair<int,int> > _faces;
public:
    Attributes(){}
    void detectFaces() ;
};

struct Unit {
private:
    std::array<cv::Mat, CLIP_SIZE> _frames;
    Attributes _features ;

public:
    Unit() ;
    Unit(std::array<cv::Mat, CLIP_SIZE> frames);
    Unit(cv::VideoCapture &vid);
    int takeFrames(cv::VideoCapture &vid );
    void addAttributes();
};

#endif // UNIT
