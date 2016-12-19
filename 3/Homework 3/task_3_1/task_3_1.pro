QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_3_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    cannon.cpp \
    othershot.cpp \
    simpleshot.cpp

HEADERS  += mainwindow.h \
    game.h \
    cannon.h \
    othershot.h \
    shotmaker.h \
    simpleshot.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
