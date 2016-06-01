TEMPLATE = app
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui testlib

SOURCES += main.cpp \
    mainwidget.cpp \
    gamefield.cpp \
    choosegamesize.cpp \
    winnerwindow.cpp

HEADERS += \
    mainwidget.h \
    gamefield.h \
    choosegamesize.h \
    winnerwindow.h \
    gamefieldtest.h

