#include "testbench.hpp"
#include "ui_testbench.h"
#include "Effects/effects.h"

#include <typeinfo>
#include <functional>
#include <chrono>
#include <climits>
#include <iostream>
#include <thread>
#include <ctime>

#include <QFileDialog>
#include <QApplication>
#include <QString>
#include <QPixmap>
#include <QWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QList>

#define _(x) #x

using namespace std;
using namespace cv;

TestBench::TestBench(QWidget *parent): QMainWindow(parent), ui(new Ui::TestBench){

    ui->setupUi(this);

    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Video"), ".", tr("Image Files (*.avi *.mp4 )"));
    VideoCapture video( filePath.toLocal8Bit().constData() );

    if (!video.isOpened()){cout << "could not open vid" << endl ;return;}
    mntg._media.clear();
    mntg.fps = video.get(CV_CAP_PROP_FPS);
    mntg.frame_width  = video.get(CV_CAP_PROP_FRAME_WIDTH);
    mntg.frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    mntg.video_partition(video);

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

    //should be able to delete video here

    //this for testing. genQueue value should be false
    Effects::genQueue(q, mntg, true);
    while (q.size()){ funcs.push_back( q.front() ); q.pop();}

    //Dynamically adds function names to scroll menue for testing multiple functions
    QWidget *container = new QWidget;
    QVBoxLayout* containerLayout = new QVBoxLayout();
    container->setLayout(containerLayout);
    this->ui->scrollArea->setWidget(container);
    for(auto func: funcs){
        QCheckBox *checkbox = new QCheckBox( QString::fromStdString(func.second) );
        containerLayout->addWidget(checkbox);
    }
}

TestBench::~TestBench()
{
    delete ui;
}

unsigned TestBench::isValid( unsigned temp ){
    if (temp==0) temp = mntg.dice();
    return temp;
}


void TestBench::on_ARGBOX_IT_editingFinished(){}

void TestBench::on_ARGBOX_PA_1_editingFinished(){}

void TestBench::on_ARGBOX_PA_2_editingFinished(){}

void TestBench::on_ARGBOX_PB_1_editingFinished(){}

void TestBench::on_ARGBOX_PB_2_editingFinished(){}

void TestBench::on_ARGBOX_MINF_editingFinished(){}

void TestBench::on_ARGBOX_SIZE_editingFinished(){}

void TestBench::on_ARGBOX_NOR_editingFinished(){}

void TestBench::on_pushButton_clicked(){

    vector<int> index;
    QList<QCheckBox*> list = this->ui->scrollArea->widget()->findChildren<QCheckBox*>(); ;

    int i = 0;
    foreach( QCheckBox *item, list){
        if( item->isChecked() ) index.push_back(i);
        i++;
    }
    if (index.size() == 0) return;

    
    double average_frun_time = 0, average_run_time = 0;
    number_of_runs = this->ui->ARGBOX_NOR->value();
    int progress = 1 ;
    this->ui->ProgressBar->setValue(0);
    this->ui->ProgressBar->setMinimum(0);
    this->ui->ProgressBar->setMaximum( number_of_runs * (index.size()) );
    cout << "GOING!" << endl;

    for( auto it: index){
        for(int i = 0; i < number_of_runs; i++){

            std::clock_t start = std::clock();

            //set start location in the clip
            arglist.it = isValid(this->ui->ARGBOX_IT->value()) % mntg._media.size();

            //set start and end location of the frame where the effect will be applied
            arglist.A.x = isValid(this->ui->ARGBOX_PA_1->value()) % mntg.frame_width;
            arglist.A.y = isValid(this->ui->ARGBOX_PA_2->value()) % mntg.frame_height;
            arglist.B.x = isValid(this->ui->ARGBOX_PB_1->value()) % mntg.frame_width;
            arglist.B.y = isValid(this->ui->ARGBOX_PB_2->value()) % mntg.frame_height;

            //set the size of the effect. Size should be checked by effect
            arglist.size = isValid(this->ui->ARGBOX_SIZE->value()) ;

            //set the minimum number of frames to opperate on
            arglist.min_frames = isValid(this->ui->ARGBOX_MINF->value()) % mntg._media.size() ;

            cout << "IT  " << arglist.it << " Out of " << mntg._media.size() << endl;
            cout << "PAx " << arglist.A.x << endl;
            cout << "PAy " << arglist.A.y << endl;
            cout << "PBx " << arglist.B.x << endl;
            cout << "PBy " << arglist.B.y << endl;
            cout << "MF  " << arglist.min_frames << endl;
            cout << "SZ  " << arglist.size << endl << endl;

            std::clock_t fStart = std::clock();

            funcs[it].first( mntg, arglist);

            average_frun_time += std::clock() - fStart;
            average_run_time  += std::clock() - start;

            this->ui->ProgressBar->setValue(progress++);
        }

        average_frun_time /= number_of_runs ;
        average_run_time /= number_of_runs ;

        cout << "Done with " << funcs[it].second << endl;
        cout << "Average run time for " << funcs[it].second << " is " << average_frun_time << " ms" << endl ;
        cout << "Average run time for function generation is " << average_run_time << " ms" << endl ;
    }
}

void TestBench::on_playVideo_clicked(){
    mntg.playVideo();
}

void TestBench::on_pushButton_2_clicked()
{
    std::clock_t start = std::clock();
    mntg.addAttributes();
    cout << "Run time for adding attributes is " << std::clock() - start << " ms" << endl ;
}
