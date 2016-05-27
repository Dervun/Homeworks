TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += testlib core

SOURCES += main.cpp \
    polinomialhash.cpp \
    hashtable.cpp \
    hashh37.cpp \
    hashfaq6.cpp \
    hashrot13.cpp \
    hashly.cpp

HEADERS += \
    hashfunction.h \
    polinomialhash.h \
    hashtable.h \
    hashh37.h \
    hashfaq6.h \
    hashrot13.h \
    hashly.h \
    hashtabletest.h

DISTFILES += \
    Harry_Potter_all_books.txt

