#include "form.hpp"
#include "ui_form.h"

#include <QFileDialog>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/highgui/highgui.hpp"

#include <QApplication>

#include "Unit.hpp"
#include "MontageClip.hpp"

using namespace std;
using namespace cv;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form){

    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.avi *.mp4 )"));

    VideoCapture video( fileName.toLocal8Bit().constData() );

   // if (!video.isOpened()) return;

    int fps = video.get(CV_CAP_PROP_FPS);
    int frame_width  = video.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    //Size video_frame_size = Size((int)frame_width,(int)frame_height);

    this->ui->SSD_FPS->display(fps);
    this->ui->SSD_Width->display(frame_width);
    this->ui->SSD_Height->display(frame_height);

    mntg.video_partition(video);
    mntg.addAttributes();



}

