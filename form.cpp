#include "form.hpp"
#include "ui_form.h"

#include <QFileDialog>
#include <QApplication>
#include <QString>
#include <QPixmap>

#include <chrono>
#include <climits>
#include <iostream>
#include "Unit.hpp"
#include "MontageClip.hpp"

using namespace std;
using namespace cv;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form){

    ui->setupUi(this);

    this->ui->playVideo->setFlat(true);
    this->ui->playVideo->setStyleSheet("* {color: gray }");

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.avi *.mp4 )"));

    VideoCapture video( filePath.toLocal8Bit().constData() );

    unsigned seed;
    if (!video.isOpened()) return;

    int fps = video.get(CV_CAP_PROP_FPS);
    int frame_width  = video.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    //Size video_frame_size = Size((int)frame_width,(int)frame_height);

    this->ui->SSD_FPS->display(fps);
    this->ui->SSD_Width->display(frame_width);
    this->ui->SSD_Height->display(frame_height);

    mntg.video_partition(video);
   // mntg.addAttributes();


    this->ui->playVideo->setFlat( false );
    this->ui->playVideo->setStyleSheet("* {color: black}");

    //try to use Qstrings here
    String temp = this->ui->seedBox->text().toLocal8Bit().constData() ;

    if( temp.size()){
        for(int i = 0; i < (int)temp.length(); ++i){
            if( isalpha(temp[i]) or isspace(temp[i] ) ){
                temp[i] = ( temp[i] % 9) + 48;
            }
        }
        seed = atoi(temp.c_str());
    }else{

        seed = std::chrono::system_clock::now().time_since_epoch().count();
        this->ui->seedBox->insert(QString::number(seed));
    }

    default_random_engine generator(seed) ;
    uniform_int_distribution<unsigned> distribution( 0, UINT_MAX );
    auto dice = bind( distribution, generator );

    cout << dice() << endl;
}

void Form::on_playVideo_clicked()
{
    if( !this->ui->playVideo->isFlat() )
        mntg.playVideo();
}

void Form::on_seedBox_editingFinished(){

}
