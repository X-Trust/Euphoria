#ifndef MONTAGECLIP
#define MONTAGECLIP

#include "Globals.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <functional>

struct eff_args {
    //MontageClip &mntg; &Form::updateProgress
    int it;
    cv::Point A;
    cv::Point B;
    unsigned min_frames;
    unsigned size;
    unsigned function_data;
};


struct Attributes{
   std::vector<cv::Rect> _faces;
   cv::Mat _frame;

   //Don't forget to add new functions to addAttributes
   void detectFaces();

};

struct MontageClip{

    std::vector<Attributes> _media;
    int frame_height;
    int frame_width;
    int fps;

    std::default_random_engine generator ;
    std::uniform_int_distribution<unsigned> distribution;
    std::queue<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > q;
    std::function<unsigned()> dice ;

    void video_partition(cv::VideoCapture &vid );
    void combineClips(cv::VideoWriter &out);
    void playVideo();
    void addAttributes();
    unsigned generateQueue();
    bool addEffects();
    void bindDice( unsigned seed );
};

#endif // MONTAGECLIP_HPP
