#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

#include "Unit.hpp"

#include <iostream>
#include <array>

using namespace cv;
using namespace std;

Unit::Unit(){}

Unit::Unit(array<Mat, CLIP_SIZE> frames){

    for (int i = 0; i < CLIP_SIZE; i++) {
        _frames[i] = frames[i];
    }
}

Unit::Unit(VideoCapture &vid){

    if (!vid.isOpened()){
        cout  << "Could not open the input video in partision phase!" << endl;
    }else{

        int i;

        for (i = 0; i < CLIP_SIZE; ++i){

            vid.read(_frames[i]); // read a frame
            if (_frames[i].empty()) break;

            imshow( "TEST", _frames[i]);
            if( waitKey( 1 ) >= 0 ) return ;

        }

        //for (; i < CLIP_SIZE; ++i) _frames[i] = _frames[i-1];
    }
}


int Unit::takeFrames( VideoCapture &vid ){

    if (!vid.isOpened()) return -1;

    for (int i = 0; i < CLIP_SIZE; ++i){
        vid.read(_frames[i]); // read a frame
        if (_frames[i].empty()){ // check if end of video
            cout << "THIS THING HERE WORKS AS EXPECTED! WHO'ED OF THUNK IT!!" << endl ;
            for (; i < CLIP_SIZE; ++i) _frames[i] = _frames[i-1];
            return 0 ;
        }
        imshow( "TEST", _frames[i]);
        waitKey( 30 ) ;
    }
    return 1 ;
}

void Unit::addAttributes(){

    //list the function for the attributes
   _features.detectFaces();

}

