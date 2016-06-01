QT       += core gui network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    ../Messenger/messenger.cpp

HEADERS  += mainwindow.h \
    client.h \
    ../Messenger/messenger.h

FORMS    += mainwindow.ui
