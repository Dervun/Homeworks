TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core testlib

SOURCES += main.cpp \
    listsinglelinked.cpp \
    listdoublelinked.cpp

HEADERS += \
    list.h \
    listsinglelinked.h \
    listdoublelinked.h \
    listtest.h

