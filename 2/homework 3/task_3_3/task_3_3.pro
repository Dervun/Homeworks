QT       += core gui\
testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_3_3
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    linkedstack.h \
    calculator.h

FORMS    += mainwindow.ui
