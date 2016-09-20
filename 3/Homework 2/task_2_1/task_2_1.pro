TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    localareanetwork.cpp \
    computer.cpp

HEADERS += \
    computer.h \
    localareanetwork.h

DISTFILES += \
    Computers.txt

