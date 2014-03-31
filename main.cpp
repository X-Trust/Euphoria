#include <iostream>
#include <QApplication>
#include "form.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Form w;
    w.show();

    return a.exec();
}
