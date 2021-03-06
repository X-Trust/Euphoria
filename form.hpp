#ifndef FORM_HPP
#define FORM_HPP

#include "MontageClip.hpp"
#include <QWidget>

namespace Ui {
class Form;

}

class Form : public QWidget{
    Q_OBJECT
    MontageClip mntg ;
public:
    int progress;
    int total_progress;
    explicit Form(QWidget *parent = 0);
    ~Form();


private slots:
    void on_pushButton_clicked();
    void on_playVideo_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_HPP
