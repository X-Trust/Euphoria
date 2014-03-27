#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/highgui/highgui.hpp"

#include <QApplication>

#include "Unit.hpp"
#include "MontageClip.hpp"
#include "form.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Form w;
    w.show();

    return a.exec();
}
