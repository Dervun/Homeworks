#pragma once
#include <QObject>
#include <QTest>

#include "sharedpointer.h"

class SharedPointerTest : public QObject
{
    Q_OBJECT
private slots:

    void createPointerTest()
    {
        SharedPointer<int> ptr(new int(42));
    }
    void dereferencePointerTest()
    {
        SharedPointer<int> ptr(new int(42));
        QCOMPARE(*ptr, 42);
    }
    void countOnePointerTest()
    {
        SharedPointer<int> ptr(new int(42));
        QCOMPARE(ptr.getCount(), 1);
    }
    void copyPointerTest()
    {
       SharedPointer<int> ptr1(new int(42));
       SharedPointer<int> ptr2(ptr1);
       QCOMPARE(*ptr1, *ptr2);
       QCOMPARE(ptr1.getCount(), 2);
       QCOMPARE(ptr1.getCount(), ptr2.getCount());
    }
    void assignmentPointerTest()
    {
        SharedPointer<int> ptr1(new int(42));
        SharedPointer<int> ptr2;
        ptr2 = ptr1;
        QCOMPARE(*ptr1, *ptr2);
        QCOMPARE(ptr1.getCount(), 2);
        QCOMPARE(ptr1.getCount(), ptr2.getCount());
    }
    void removePointerTest()
    {
        SharedPointer<int> ptr1(new int(42));
        SharedPointer<int> *ptr2 = new SharedPointer<int>(ptr);
        delete ptr2;
        QCOMPARE(ptr1.getCount(), 1);
    }
    void assignmentToExistingPointerTest()
    {
        SharedPointer<int> ptr1(new int(42));
        SharedPointer<int> ptr2(new int(77));
        SharedPointer<int> ptr3 = ptr2;
        ptr3 = ptr1;
        QCOMPARE(ptr2.getCount(), 1);
        QCOMPARE(ptr1.getCount(), 2);
    }
};
