#include "MontageClip.hpp"
#include "Unit.hpp"
#include <vector>

using namespace std;
using namespace cv;

int MontageClip::video_partition( VideoCapture &vid ){
    if (!vid.isOpened()){
        cout << "Could not open the input video in the Montage_clip partision phase!" << endl;
        cout << vid.isOpened() << endl ;
        return -1;
    }
    for(;;){
        Unit temp ;
        if( !temp.takeFrames(vid) ) return 1 ;
        _units.push_back( temp );
    }
    return 1 ;
}

void MontageClip::addAttributes(){

    for(Unit &u : _units ){
        u.addAttributes() ;
    }
}

void MontageClip::combineClips(VideoWriter &out) {
    for (Unit u : _units) {
        for (int i = 0; i < globals::clip_size; i++) {
            out.write(u._frames[i]);
        }
    }
}

void MontageClip::playVideo() {
    namedWindow("MONTAGE_PLAY_WINDOW");
    for (Unit u : _units) {
        for (int i = 0; i < globals::clip_size; i++) {
            imshow("MONTAGE_PLAY_WINDOW", u._frames[i]);
            waitKey(30);
        }
    }
    destroyWindow("MONTAGE_PLAY_WINDOW");
}
