TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += testlib core

SOURCES += main.cpp \
    localareanetwork.cpp \
    computer.cpp \
    networkfortest.cpp

HEADERS += \
    computer.h \
    localareanetwork.h \
    computertest.h \
    localareanetworktest.h \
    networkfortest.h

DISTFILES += \
    Computers.txt \
    Test_file.txt

