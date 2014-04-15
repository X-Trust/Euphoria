#include "opencv2/core/core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include "MontageClip.hpp"

#include <iostream>
#include <array>

using namespace std;
using namespace cv;

void Attributes::detectFaces(){
    cout << "processing frame" << endl;

    CascadeClassifier face_cas;
    face_cas.load(globals::classifier_path);
    Mat resized = _frame;
    Mat gs; // grayscale frame

    //resize(frame, resized, Size(320, 240), 0, 0);

    cvtColor(resized, gs, CV_BGR2GRAY);
    equalizeHist(gs, gs);

    // detect faces of a reasonable size and put the rectangles in _faces
    face_cas.detectMultiScale(gs, _faces);

    cout << _faces.size() << endl;

    // TEST, draw rectangles on frame
    for (unsigned int i = 0; i < _faces.size(); i++) {
        //Point pt1(_faces[i].x*2 + _faces[i].width*2, _faces[i].y*2 + _faces[i].height*2);
        //Point pt2(_faces[i].x*2, _faces[i].y*2);

        Point pt1(_faces[i].x + _faces[i].width, _faces[i].y + _faces[i].height);
        Point pt2(_faces[i].x, _faces[i].y);

        rectangle(_frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
    }
}
