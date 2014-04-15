#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include "Unit.hpp"

#include <iostream>
#include <array>

using namespace cv;
using namespace std;
/*
Unit::Unit(){}

void Unit::transposeFrame( cv::Mat &image){

    if (image.empty()) return;
    Mat new_image( image.rows * 3, image.cols * 3, CV_8UC3, Scalar(0,0,255));

    Rect dim = Rect( image.rows, image.cols, image.rows * 2, image.cols * 2);

    Mat subview = new_image(dim);

    image.copyTo(subview);

    image = subview;
}
Unit::Unit(array<Mat, globals::clip_size> frames){

    for (int i = 0; i < globals::clip_size; i++) {
        _frames[i] = frames[i];
    }
}

Unit::Unit(VideoCapture &vid){

    if (!vid.isOpened()){
        cout  << "Could not open the input video in partision phase!" << endl;
    }else{

        int i;

        for (i = 0; i < globals::clip_size; ++i){

            vid.read(_frames[i]); // read a frame
            if (_frames[i].empty()) break;

            imshow( "TEST", _frames[i]);
            if( waitKey( 1 ) >= 0 ) return ;

        }

        //for (; i < globals::clip_size; ++i) _frames[i] = _frames[i-1];
    }
}

int Unit::takeFrames( VideoCapture &vid ){

    if (!vid.isOpened()) return -1;

    for (int i = 0; i < globals::clip_size; ++i){
        vid.read(_frames[i]); // read a frame
        //   transposeFrame( _frames[i] );
        if (_frames[i].empty()){ // check if end of video
            for (; i < globals::clip_size; ++i) _frames[i] = _frames[i-1];
            return 0 ;
        }
    }
    return 1 ;
}

void Unit::addAttributes(){
    //list the function for the attributes
    for (int i = 0; i < globals::clip_size; i++) {
        _features[i].detectFaces(_frames[i]);

    }
}

*/
