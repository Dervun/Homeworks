#pragma once
#include <QObject>
#include <QtTest>

#include "linkedstack.h"
#include "arraystack.h"

class StackTest : public QObject
{
    Q_OBJECT
public:
    StackTest(bool isLinked) : isLinked(isLinked){}
private:
    Stack<int>* s;
    bool isLinked;
private slots:
    void init()
    {
        if (isLinked)
            s = new LinkedStack<int>;
        else
            s = new ArrayStack<int>;
    }

    void cleanup()
    {
        delete s;
    }

    void pushTest()
    {
        s->push(42);
        QCOMPARE(s->top(), 42);
    }

    void emptyStackTest()
    {
        s->push(42);
        QVERIFY(!s->isEmpty());
    }

    void popTest()
    {
        s->push(42);
        QCOMPARE(s->pop(), 42);
        QVERIFY(s->isEmpty());
    }

    void manyPushAndPopTest()
    {
        for (int i = 0; i < 50; i++)
            s->push(i);
        for (int i = 49; i >= 0; i--)
            QCOMPARE(s->pop(), i);
        QVERIFY(s->isEmpty());
    }
};
