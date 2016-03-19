TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consolewriter.cpp \
    filewriter.cpp

HEADERS += \
    writer.h \
    consolewriter.h \
    filewriter.h

