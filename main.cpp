#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/highgui/highgui.hpp"

#include "Unit.hpp"
#include "MontageClip.hpp"

using namespace std;
using namespace cv;

int main(){

    VideoCapture video("F:\\projects\\C++\\Euphoria\\test_lab_small.avi") ;
    MontageClip mntg ;

    if (!video.isOpened()){
        cout  << "FOREVER SADNESSS!!!!!!!" << endl;
        return -1;
    }

    //get the frames per seconds of the video
    double fps = video.get(CV_CAP_PROP_FPS);
    cout << "Frame per seconds : " << fps << endl;

    //video may no longer be needed at this point
    mntg.video_partition( video ) ;

    //add all the atributes given in the Attribute class
    mntg.addAttributes();


    return 0;
}
