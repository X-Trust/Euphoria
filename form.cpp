#include "form.hpp"
#include "Unit.hpp"
#include "MontageClip.hpp"
#include "ui_form.h"

#include <QFileDialog>
#include <QApplication>
#include <QString>
#include <QPixmap>
#include <QWidget>

#include <typeinfo>
#include <functional>
#include <chrono>
#include <climits>
#include <iostream>
#include <thread>

using namespace std;
using namespace cv;

void stuff(){
    cout << "THIS" << endl;
}

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form){

    ui->setupUi(this);
    this->ui->playVideo->setFlat(true);

    progress = 0 ;
    total_progress = 0;
}

Form::~Form(){
    delete ui;
}

void Form::on_pushButton_clicked(){

    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Video"), ".", tr("Image Files (*.avi *.mp4 )"));
    VideoCapture video( filePath.toLocal8Bit().constData() );

     if (!video.isOpened()){
        cout << "could not open vid" << endl ;
        return;
    }

    mntg._media.clear();
    mntg.fps = video.get(CV_CAP_PROP_FPS);
    mntg.frame_width  = video.get(CV_CAP_PROP_FRAME_WIDTH);
    mntg.frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    //Size video_frame_size = Size((int)frame_width,(int)frame_height);

    this->ui->SSD_FPS->display(mntg.fps);
    this->ui->SSD_Width->display(mntg.frame_width);
    this->ui->SSD_Height->display(mntg.frame_height);
    this->ui->playVideo->setFlat( false );
    //try to use Qstrings here
    String temp = this->ui->seedBox->text().toLocal8Bit().constData() ;

    unsigned seed;
    if (temp.size()){
        for (int i = 0; i < (int)temp.length(); ++i){
            if (isalpha(temp[i]) or isspace(temp[i])){
                temp[i] = (temp[i] % 9) + 48;
            }
        }
        seed = atoi(temp.c_str());
    }else{
        seed = std::chrono::system_clock::now().time_since_epoch().count();
        this->ui->seedBox->insert(QString::number(seed));
    }

    mntg.bindDice(seed);
    mntg.video_partition(video);
    mntg.generateQueue();

    this->ui->progressBar->setMaximum(0);
    this->ui->progressBar->setMaximum( mntg.q.size() );
    this->ui->progressBar->setValue(0);

    progress = 0;
    while(mntg.q.size()){
        mntg.addEffects();
        this->ui->progressBar->setValue(++progress);
    }
}

void Form::on_playVideo_clicked(){
    if( !this->ui->playVideo->isFlat() )
        mntg.playVideo();
}


void Form::on_advancedOptions_clicked(){


    this->ui->advancedOptions->hide();

    for (int i = 400; i <= 700; i++){
        this->resize(1000, i);
        waitKey(15);
    }

}
