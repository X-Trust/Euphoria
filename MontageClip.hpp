#ifndef MONTAGECLIP
#define MONTAGECLIP

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Unit.hpp>

#include <iostream>
#include <list>
#include <vector>

struct MontageClip{
private:
    std::list<Unit>       _units;

    int _size;
public:
    // MontageClip(std::list<Unit>) : _size(50){}
    int video_partition(cv::VideoCapture &vid );
    void combineClips(cv::VideoWriter &out);
    void playVideo();
    void addAttributes();
};


#endif // MONTAGECLIP_HPP
