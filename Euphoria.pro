TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    Unit.cpp \
    MontageClip.cpp \
    Attributes.cpp

INCLUDEPATH += C:\Qt\build_with_Qt248\debug\include

LIBS += -LC:\Qt\build_with_Qt248\debug\x64\mingw\bin\
             -lopencv_core248d\
             -lopencv_highgui248d\
             -lopencv_imgproc248d\
             -lopencv_video248d\
             -lopencv_ml248d\
             -lopencv_features2d248d\
             -lopencv_calib3d248d\
             -lopencv_objdetect248d\
             -lopencv_contrib248d\
             -lopencv_legacy248d\
             -lopencv_flann248d\
             -lopencv_nonfree248d\

HEADERS += \
    MontageClip.hpp \
  Unit.hpp \
    Globals.h
