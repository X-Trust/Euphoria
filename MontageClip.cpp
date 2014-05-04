#include <vector>
#include <queue>
#include <functional>

#include "MontageClip.hpp"
#include "Effects/effects.h"
#include "Globals.h"

using namespace std;
using namespace cv;

unsigned MontageClip::generateQueue(){
    Effects::genQueue(q, *this, false);
    return q.size();
}

void MontageClip::video_partition( VideoCapture &vid ){
    _media.resize(vid.get(CV_CAP_PROP_FRAME_COUNT)); // Sets the starting size of the array
    cout << _media.size() << endl ;
    for(unsigned i = 0; i < _media.size(); i++)
         vid.read( _media[i]._frame );


}

//if(!_media._frame.takeFrames(vid)) return;
// _units.push_back( temp );

void MontageClip::addAttributes(){
cout << "----------> " << _media.size() << endl;
    for(unsigned i = 0; i < _media.size(); i++)
         _media[i].detectFaces();
    std::cout << "THIS YOLO SSWAG" << endl;

        //Dont forget to add any additional functions
}

void MontageClip::combineClips(VideoWriter &out){
   for(unsigned i = 0; i < _media.size(); i++)
        out.write(_media[i]._frame);


}

void MontageClip::playVideo(){
    cv::namedWindow("MONTAGE_PLAY_WINDOW");

    cv::imshow("MONTAGE_PLAY_WINDOW", _media[0]._frame );
    cv::waitKey(30);
    for ( auto video : _media ){
        cv::imshow("MONTAGE_PLAY_WINDOW", video._frame );
        cv::waitKey(30);
    }
    cv::destroyWindow("MONTAGE_PLAY_WINDOW");
}

bool MontageClip::addEffects(){

    eff_args arglist;

    //set start location in the clip
    arglist.it = dice() % _media.size();

    //set start and end location of the frame where the effect will be applied
    arglist.A.x = dice() % frame_width;
    arglist.A.y = dice() % frame_height;

    arglist.B.x = dice() % frame_width;
    arglist.B.y = dice() % frame_height;

    //set the size of the effect. Size should be checked by effect
    arglist.size = dice();

    //set the minimum number of frames to opperate on
    //This should be modded by the function
    arglist.min_frames = dice();
    std::cout << dice() << endl;
    EffectFactory::makeEffect( (int)dice() )( *this, arglist);

    return true;
}

void MontageClip::bindDice(unsigned seed){
    generator    = default_random_engine(seed);
    distribution = std::uniform_int_distribution<unsigned>( 1, UINT_MAX);
    dice = bind(distribution, generator);
}

