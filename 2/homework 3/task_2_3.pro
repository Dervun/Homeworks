TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    linkedlist.cpp \
    listscomparator.cpp \
    sortedset.cpp \
    sortedsettest.cpp

HEADERS += \
    linkedlist.h \
    listscomparator.h \
    sortedset.h \
    sortedsettest.h

