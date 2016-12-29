QT       += core gui
QT       += network

CONFIG += debug c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_4_1
TEMPLATE = app


SOURCES += main.cpp\
    GameComponent/game.cpp \
    GameComponent/cannon.cpp \
    NetworkComponent/client.cpp \
    NetworkComponent/server.cpp \
    GameComponent/mainwindow.cpp \
    GameComponent/megashot.cpp \
    GameComponent/simpleshot.cpp \
    GameComponent/shotmaker.cpp \
    NetworkComponent/networkobject.cpp

HEADERS  += \
    GameComponent/game.h \
    GameComponent/cannon.h \
    NetworkComponent/client.h \
    NetworkComponent/server.h \
    GameComponent/mainwindow.h \
    GameComponent/megashot.h \
    GameComponent/simpleshot.h \
    GameComponent/shotmaker.h \
    NetworkComponent/networkobject.h

FORMS    += \
    GameComponent/mainwindow.ui

RESOURCES += \
    images.qrc
