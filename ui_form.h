/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QLCDNumber *SSD_FPS;
    QLCDNumber *SSD_Height;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLCDNumber *SSD_Width;
    QLabel *label_3;
    QPushButton *playVideo;
    QLineEdit *seedBox;
    QLabel *Seed;
    QProgressBar *progressBar;
    QPushButton *advancedOptions;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1000, 423);
        QIcon icon;
        icon.addFile(QStringLiteral("fedora.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Form->setWindowIcon(icon);
        Form->setToolTipDuration(0);
        Form->setAutoFillBackground(false);
        Form->setStyleSheet(QStringLiteral("color: black"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 50, 160, 80));
        pushButton->setStyleSheet(QLatin1String("color: gray;\n"
"color: black;\n"
"font: 19pt \"Comic Sans MS\";"));
        SSD_FPS = new QLCDNumber(Form);
        SSD_FPS->setObjectName(QStringLiteral("SSD_FPS"));
        SSD_FPS->setGeometry(QRect(220, 50, 161, 81));
        SSD_FPS->setDigitCount(4);
        SSD_Height = new QLCDNumber(Form);
        SSD_Height->setObjectName(QStringLiteral("SSD_Height"));
        SSD_Height->setGeometry(QRect(620, 50, 161, 81));
        SSD_Height->setDigitCount(4);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 10, 161, 31));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 10, 161, 31));
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 330, 961, 21));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        line->setPalette(palette);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SSD_Width = new QLCDNumber(Form);
        SSD_Width->setObjectName(QStringLiteral("SSD_Width"));
        SSD_Width->setGeometry(QRect(420, 50, 161, 81));
        SSD_Width->setDigitCount(4);
        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(620, 10, 161, 31));
        playVideo = new QPushButton(Form);
        playVideo->setObjectName(QStringLiteral("playVideo"));
        playVideo->setGeometry(QRect(820, 50, 161, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 213, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 191, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 113, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(255, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        playVideo->setPalette(palette1);
        playVideo->setStyleSheet(QLatin1String("\n"
"font: 20pt \"Comic Sans MS\";"));
        seedBox = new QLineEdit(Form);
        seedBox->setObjectName(QStringLiteral("seedBox"));
        seedBox->setGeometry(QRect(150, 170, 731, 81));
        seedBox->setLayoutDirection(Qt::LeftToRight);
        seedBox->setStyleSheet(QStringLiteral("font: 36pt \"Comic Sans MS\";"));
        seedBox->setMaxLength(25);
        seedBox->setFrame(true);
        Seed = new QLabel(Form);
        Seed->setObjectName(QStringLiteral("Seed"));
        Seed->setGeometry(QRect(20, 170, 131, 80));
        QFont font;
        font.setPointSize(36);
        font.setUnderline(false);
        Seed->setFont(font);
        progressBar = new QProgressBar(Form);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 280, 960, 25));
        progressBar->setValue(0);
        advancedOptions = new QPushButton(Form);
        advancedOptions->setObjectName(QStringLiteral("advancedOptions"));
        advancedOptions->setGeometry(QRect(400, 350, 200, 45));
        advancedOptions->setStyleSheet(QStringLiteral("font: 16pt \"Comic Sans MS\";"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        pushButton->setText(QApplication::translate("Form", "Select Video ", 0));
        label->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:20pt; text-decoration: underline;\">FPS</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:20pt; text-decoration: underline;\">Height</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:20pt; text-decoration: underline;\">Width</span></p></body></html>", 0));
        playVideo->setText(QApplication::translate("Form", "Play Video", 0));
        seedBox->setText(QString());
        Seed->setText(QApplication::translate("Form", "Seed:", 0));
        advancedOptions->setText(QApplication::translate("Form", "AdvancedOptions", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
