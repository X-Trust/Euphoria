#ifndef TESTBENCH_HPP
#define TESTBENCH_HPP

#include <QMainWindow>
#include <functional>
#include "MontageClip.hpp"
#include "Unit.hpp"
#include "Globals.h"

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
    std::queue< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > q;
    std::vector<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > funcs;

    int number_of_runs;

    unsigned isValid(unsigned temp);

private slots:


    void on_ARGBOX_IT_editingFinished();

    void on_ARGBOX_PA_1_editingFinished();

    void on_ARGBOX_PA_2_editingFinished();

    void on_ARGBOX_PB_1_editingFinished();

    void on_ARGBOX_PB_2_editingFinished();

    void on_ARGBOX_MINF_editingFinished();

    void on_ARGBOX_SIZE_editingFinished();

    void on_ARGBOX_NOR_editingFinished();

    void on_pushButton_clicked();

    void on_playVideo_clicked();

private:
    Ui::TestBench *ui;
};

#endif // TESTBENCH_HPP
