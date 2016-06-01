QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_3_2
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    calculator.cpp

HEADERS  += \
    mainwindow.h \
    calculator.h

FORMS    += \
    mainwindow.ui
