#pragma once
#include <QObject>
#include <QtTest>

#include "queue.h"

class QueueTest : public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject* parent = 0) : QObject(parent){}
private slots:
    void init()
    {
        q = new Queue<int, int>;
    }

    void cleanup()
    {
        delete q;
    }

    void pushTest()
    {
        q->enqueue(5, 5);
        QVERIFY(q->size() == 1);
    }

    void manyPushTest()
    {
        for (int i = 0; i < 10; i++)
            q->enqueue(i, i % 2);
        QVERIFY(q->size() == 10);
    }

    void pushAndPopTest()
    {
        q->enqueue(5, 3);
        QVERIFY(q->dequeue() == 5);
        QVERIFY(q->size() == 0);
    }

    void pushMoreThenPop()
    {
        for (int i = 0; i < 10; i++)
            q->enqueue(i, i % 2);
        QVERIFY(q->dequeue());
        QVERIFY(q->size() == 9);
        QVERIFY(q->dequeue());
        QVERIFY(q->size() == 8);
        QVERIFY(q->dequeue());
        QVERIFY(q->size() == 7);
    }

    void correctOfPopTest()
    {
        for (int i = 0; i < 10; i++)
            q->enqueue(i, i % 3);
        QVERIFY(q->dequeue() == 2);
        QVERIFY(q->dequeue() == 5);
        QVERIFY(q->dequeue() == 8);
        QVERIFY(q->dequeue() == 1);
        QVERIFY(q->dequeue() == 4);
        QVERIFY(q->dequeue() == 7);
        QVERIFY(q->dequeue() == 0);
        QVERIFY(q->dequeue() == 3);
        QVERIFY(q->dequeue() == 6);
        QVERIFY(q->dequeue() == 9);
    }

    void tryPopMoreThanPushTest()
    {
        q->enqueue(3, 3);
        q->dequeue();
        try
        {
            q->dequeue();
        }
        catch (int errorCode)
        {
            QVERIFY(errorCode == 0);
        }
        QVERIFY(q->size() == 0);
    }

private:
    Queue<int, int>* q;
};
