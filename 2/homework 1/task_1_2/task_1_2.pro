TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core testlib

SOURCES += main.cpp \
    calculator.cpp

HEADERS += \
    arraystack.h \
    stack.h \
    linkedstack.h \
    calculator.h \
    calculatortest.h \
    stacktest.h

