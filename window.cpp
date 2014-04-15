#include "window.hpp"



Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_getVideo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
}
