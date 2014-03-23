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

    VideoCapture video("test_lab_small.avi"); //video("F:\\projects\\C++\\Euphoria\\test_lab_small.avi") ;
    VideoWriter  outputVideo;
    MontageClip  mntg ;

    double fps = video.get(CV_CAP_PROP_FPS);
    double frame_width  = video.get(CV_CAP_PROP_FRAME_WIDTH);
    double frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    Size video_frame_size = Size((int)frame_width,(int)frame_height);

    outputVideo.open("FINAL_VIDEO.avi", -1, fps, video_frame_size, true);

    if (!video.isOpened())       return -1;
    if (!outputVideo.isOpened()) return -1;

    cout << "Frame per seconds:  " << fps << endl;
    cout << "Video frame width:  " << frame_width << endl;
    cout << "Video frame height: " << frame_height << endl;

    //video may no longer be needed at this point
    mntg.video_partition( video ) ;

    //add all the atributes given in the Attribute class
    mntg.addAttributes();


    return 0;
}
