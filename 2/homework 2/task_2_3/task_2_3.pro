TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    linkedlist.cpp \
    sortedset.cpp \
    sortedsettest.cpp \
    listcomparable.cpp

HEADERS += \
    linkedlist.h \
    sortedset.h \
    sortedsettest.h \
    listcomparable.h

