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

    for( auto it: _units ){
        it.addAttributes() ;
    }
}
