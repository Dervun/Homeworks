QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_4_1
TEMPLATE = app


SOURCES += main.cpp \
    GameComponent/cannon.cpp \
    GameComponent/game.cpp \
    GameComponent/mainwindow.cpp \
    GameComponent/othershot.cpp \
    GameComponent/simpleshot.cpp


RESOURCES += \
    images.qrc

FORMS += \
    GameComponent/mainwindow.ui

HEADERS += \
    GameComponent/cannon.h \
    GameComponent/game.h \
    GameComponent/mainwindow.h \
    GameComponent/othershot.h \
    GameComponent/shotmaker.h \
    GameComponent/simpleshot.h
