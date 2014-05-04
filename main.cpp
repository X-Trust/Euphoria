#include <iostream>
#include <QApplication>
#include "form.hpp"
#include "testbench.hpp"
using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
  Form w;
   w.show();
//  TestBench w;
//  w.show();
    return a.exec();
}
