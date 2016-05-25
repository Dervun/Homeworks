TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core testlib

SOURCES += main.cpp \
    operator.cpp \
    operand.cpp \
    calculator.cpp

HEADERS += \
    treenode.h \
    operator.h \
    operand.h \
    calculator.h \
    treetest.h

