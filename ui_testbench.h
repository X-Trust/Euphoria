/********************************************************************************
** Form generated from reading UI file 'testbench.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTBENCH_H
#define UI_TESTBENCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestBench
{
public:
    QWidget *centralwidget;
    QProgressBar *ProgressBar;
    QSpinBox *ARGBOX_IT;
    QSpinBox *ARGBOX_MINF;
    QSpinBox *ARGBOX_SIZE;
    QSpinBox *ARGBOX_PA_1;
    QSpinBox *ARGBOX_PA_2;
    QSpinBox *ARGBOX_PB_1;
    QSpinBox *ARGBOX_PB_2;
    QPushButton *pushButton;
    QLineEdit *seedBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *ARGBOX_NOR;
    QLabel *label_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *playVideo;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QPushButton *fullTest;
    QMenuBar *menubar;
    QMenu *menuTestBench;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestBench)
    {
        if (TestBench->objectName().isEmpty())
            TestBench->setObjectName(QStringLiteral("TestBench"));
        TestBench->resize(1072, 681);
        centralwidget = new QWidget(TestBench);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ProgressBar = new QProgressBar(centralwidget);
        ProgressBar->setObjectName(QStringLiteral("ProgressBar"));
        ProgressBar->setGeometry(QRect(10, 610, 1051, 23));
        ProgressBar->setValue(0);
        ProgressBar->setInvertedAppearance(false);
        ARGBOX_IT = new QSpinBox(centralwidget);
        ARGBOX_IT->setObjectName(QStringLiteral("ARGBOX_IT"));
        ARGBOX_IT->setGeometry(QRect(410, 150, 101, 71));
        ARGBOX_IT->setStyleSheet(QStringLiteral("font: 20pt \"MS Shell Dlg 2\";"));
        ARGBOX_IT->setMaximum(99999);
        ARGBOX_MINF = new QSpinBox(centralwidget);
        ARGBOX_MINF->setObjectName(QStringLiteral("ARGBOX_MINF"));
        ARGBOX_MINF->setGeometry(QRect(750, 150, 91, 71));
        ARGBOX_MINF->setStyleSheet(QStringLiteral("font: 20pt \"MS Shell Dlg 2\";"));
        ARGBOX_MINF->setMaximum(99999);
        ARGBOX_SIZE = new QSpinBox(centralwidget);
        ARGBOX_SIZE->setObjectName(QStringLiteral("ARGBOX_SIZE"));
        ARGBOX_SIZE->setGeometry(QRect(860, 150, 91, 71));
        ARGBOX_SIZE->setStyleSheet(QStringLiteral("font: 20pt \"MS Shell Dlg 2\";"));
        ARGBOX_SIZE->setMaximum(99999);
        ARGBOX_PA_1 = new QSpinBox(centralwidget);
        ARGBOX_PA_1->setObjectName(QStringLiteral("ARGBOX_PA_1"));
        ARGBOX_PA_1->setGeometry(QRect(530, 150, 91, 31));
        ARGBOX_PA_1->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        ARGBOX_PA_1->setMaximum(99999);
        ARGBOX_PA_2 = new QSpinBox(centralwidget);
        ARGBOX_PA_2->setObjectName(QStringLiteral("ARGBOX_PA_2"));
        ARGBOX_PA_2->setGeometry(QRect(530, 190, 91, 31));
        ARGBOX_PA_2->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        ARGBOX_PA_2->setMaximum(99999);
        ARGBOX_PB_1 = new QSpinBox(centralwidget);
        ARGBOX_PB_1->setObjectName(QStringLiteral("ARGBOX_PB_1"));
        ARGBOX_PB_1->setGeometry(QRect(640, 150, 91, 31));
        ARGBOX_PB_1->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        ARGBOX_PB_1->setMaximum(99999);
        ARGBOX_PB_2 = new QSpinBox(centralwidget);
        ARGBOX_PB_2->setObjectName(QStringLiteral("ARGBOX_PB_2"));
        ARGBOX_PB_2->setGeometry(QRect(640, 190, 91, 31));
        ARGBOX_PB_2->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        ARGBOX_PB_2->setMaximum(99999);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(860, 250, 91, 81));
        seedBox = new QLineEdit(centralwidget);
        seedBox->setObjectName(QStringLiteral("seedBox"));
        seedBox->setGeometry(QRect(30, 40, 421, 41));
        seedBox->setMaxLength(25);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 130, 111, 21));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(530, 130, 111, 21));
        label_3->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(640, 130, 111, 21));
        label_4->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(750, 130, 111, 21));
        label_5->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(860, 130, 111, 21));
        label_6->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 130, 121, 21));
        label_7->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        ARGBOX_NOR = new QSpinBox(centralwidget);
        ARGBOX_NOR->setObjectName(QStringLiteral("ARGBOX_NOR"));
        ARGBOX_NOR->setGeometry(QRect(280, 150, 90, 70));
        ARGBOX_NOR->setStyleSheet(QStringLiteral("font: 20pt \"MS Shell Dlg 2\";"));
        ARGBOX_NOR->setMaximum(9999);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 120, 261, 31));
        label_8->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        label_8->setMargin(0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 150, 231, 181));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 179));
        scrollArea->setWidget(scrollAreaWidgetContents);
        playVideo = new QPushButton(centralwidget);
        playVideo->setObjectName(QStringLiteral("playVideo"));
        playVideo->setGeometry(QRect(750, 370, 211, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 250, 91, 81));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 10, 261, 31));
        label_9->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        label_9->setMargin(0);
        fullTest = new QPushButton(centralwidget);
        fullTest->setObjectName(QStringLiteral("fullTest"));
        fullTest->setGeometry(QRect(750, 250, 91, 81));
        TestBench->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestBench);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1072, 21));
        menuTestBench = new QMenu(menubar);
        menuTestBench->setObjectName(QStringLiteral("menuTestBench"));
        TestBench->setMenuBar(menubar);
        statusbar = new QStatusBar(TestBench);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestBench->setStatusBar(statusbar);

        menubar->addAction(menuTestBench->menuAction());

        retranslateUi(TestBench);

        QMetaObject::connectSlotsByName(TestBench);
    } // setupUi

    void retranslateUi(QMainWindow *TestBench)
    {
        TestBench->setWindowTitle(QApplication::translate("TestBench", "MainWindow", 0));
        pushButton->setText(QApplication::translate("TestBench", "GO", 0));
        label_2->setText(QApplication::translate("TestBench", "Starting Frame", 0));
        label_3->setText(QApplication::translate("TestBench", "Point A", 0));
        label_4->setText(QApplication::translate("TestBench", "Point B", 0));
        label_5->setText(QApplication::translate("TestBench", "Min Frames", 0));
        label_6->setText(QApplication::translate("TestBench", "Size", 0));
        label_7->setText(QApplication::translate("TestBench", "Number of Runs", 0));
        label_8->setText(QApplication::translate("TestBench", "Functions Test", 0));
        playVideo->setText(QApplication::translate("TestBench", "PLay Video", 0));
        pushButton_2->setText(QApplication::translate("TestBench", "Add Attributes", 0));
        label_9->setText(QApplication::translate("TestBench", "Seed", 0));
        fullTest->setText(QApplication::translate("TestBench", "Full vid test", 0));
        menuTestBench->setTitle(QApplication::translate("TestBench", "TestBench", 0));
    } // retranslateUi

};

namespace Ui {
    class TestBench: public Ui_TestBench {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBENCH_H
