#-------------------------------------------------
#
# Project created by QtCreator 2013-01-04T13:40:58
#
#-------------------------------------------------

QT       += core gui

TARGET = 490UIAPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DataPoint.cpp \
    heatmap.cpp \
    Communications.cpp

HEADERS  += mainwindow.h \
    DataPoint.h \
    heatmap.h \
    Communication.h

INCLUDEPATH += "D:/boost_1_52_0/boost_1_52_0"
INCLUDEPATH += "D:\Qt\4.8.3\include\QtCore"
INCLUDEPATH += "D:\Qt\4.8.3\include"


LIBS += "D:\boost_1_52_0\boost_1_52_0\stage\lib\libboost_system-mgw46-mt-1_52.a"
LIBS += "C:\MinGW\lib\libws2_32.a"

FORMS    += mainwindow.ui
