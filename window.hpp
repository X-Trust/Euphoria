#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "window.hpp"


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

#include <string>
namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void on_getVideo_clicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_HPP
