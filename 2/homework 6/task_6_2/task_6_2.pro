TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core testlib

SOURCES += main.cpp \
    uniquelist.cpp \
    linkedlist.cpp

HEADERS += \
    uniquelist.h \
    linkedlist.h \
    uniquelisttest.h

