#include "MontageClip.hpp"
#include "Unit.hpp"
#include "Effects/effects.h"
#include "Globals.h"

#include <vector>
#include <queue>
#include <functional>

using namespace std;
using namespace cv;



unsigned MontageClip::generateQueue(){
    Effects::genQueue(q, *this);
    return q.size();
}

void MontageClip::video_partition( VideoCapture &vid ){
    for (;;){
        Unit temp;
        if(!temp.takeFrames(vid)) return;
        _units.push_back( temp );
    }
}

void MontageClip::addAttributes(){
    for (Unit &u : _units){
        u.addAttributes() ;
    }
}

void MontageClip::combineClips(VideoWriter &out){
    for (Unit u : _units) {
        for (int i = 0; i < globals::clip_size; i++){
            out.write(u._frames[i]);
        }
    }
}

void MontageClip::playVideo(){
    namedWindow("MONTAGE_PLAY_WINDOW");
    for (Unit u : _units){
        for (int i = 0; i < globals::clip_size; i++){
            imshow("MONTAGE_PLAY_WINDOW", u._frames[i]);
            waitKey(30);
        }
    }
    destroyWindow("MONTAGE_PLAY_WINDOW");
}

bool MontageClip::addEffects(){

    eff_args arglist;

   // while(!q.empty()){
        //set start location in the clip
        arglist.it = _units.begin(); advance( arglist.it, (dice() % _units.size()));

        //set start and end location of the frame where the effect will be applied
        arglist.A.x = dice() % frame_width; arglist.A.y = dice() % frame_height;
        arglist.B.x = dice() % frame_width; arglist.B.y = dice() % frame_height;

        //set the size of the effect. Size should be checked by effect
        arglist.size = dice();

        //set the minimum number of frames to opperate on
        arglist.min_frames = dice();

        q.front()(*this,arglist);

        q.pop();
    //}
    return true;
}

void MontageClip::bindDice(unsigned seed){
    generator    = default_random_engine(seed);
    distribution = std::uniform_int_distribution<unsigned>( 0, UINT_MAX );
    dice = bind(distribution, generator);
}

