QT       += core gui network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        server.cpp \
    ../Messenger/messenger.cpp

HEADERS  += mainwindow.h \
    server.h \
    ../Messenger/messenger.h

FORMS    += mainwindow.ui
