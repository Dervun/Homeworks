TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += testlib core

SOURCES += main.cpp \
    localareanetwork.cpp \
    computer.cpp

HEADERS += \
    computer.h \
    localareanetwork.h \
    computertest.h

DISTFILES += \
    Computers.txt

