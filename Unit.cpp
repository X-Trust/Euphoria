#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include "Unit.hpp"

#include <iostream>
#include <array>

using namespace cv;
using namespace std;

Unit::Unit(){}

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
        if (_frames[i].empty()){ // check if end of video
            cout << "THIS THING HERE WORKS AS EXPECTED! WHO'D OF THUNK IT!!" << endl ;
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

