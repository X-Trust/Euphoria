#ifndef TESTBENCH_HPP
#define TESTBENCH_HPP

#include <QMainWindow>
#include <functional>
#include "MontageClip.hpp"
#include "Unit.hpp"
#include "Globals.h"
#include "Effects/effects.h"

namespace Ui {
class TestBench;
}

class TestBench : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestBench(QWidget *parent = 0);
    ~TestBench();

    eff_args arglist;
    MontageClip mntg;
    EffectFactory factory;
    std::queue< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > q;// dont need
    std::vector<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > funcs; // dont need

    int number_of_runs;

    unsigned isValid(unsigned temp);

private slots:
    void on_pushButton_clicked();

    void on_playVideo_clicked();

    void on_pushButton_2_clicked();

    void on_fullTest_clicked();

private:
    Ui::TestBench *ui;
};

#endif // TESTBENCH_HPP
