QT       += core gui network webkitwidgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_8_2
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    bash.cpp

HEADERS  += mainwindow.h \
    bash.h

FORMS    += mainwindow.ui
