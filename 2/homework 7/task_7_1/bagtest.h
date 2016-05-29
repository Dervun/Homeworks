#pragma once
#include <QObject>
#include <QtTest>

#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
private:
    Bag<int>* bag;
    int value = 42;
private slots:
    void init()
    {
        bag = new Bag<int>;
    }

    void cleanup()
    {
        delete bag;
    }

    void pushElementWithOneQuantityTest()
    {
        bag->add(value, 1);
        QCOMPARE(bag->getSize(), 1);
        QVERIFY(bag->exists(value));
        QCOMPARE(bag->getQuantity(value), 1);
    }

    void pushElementWithMoteThanOneQuantityTest()
    {
        bag->add(value, 11);
        QCOMPARE(bag->getSize(), 1);
        QCOMPARE(bag->getQuantity(value), 11);
    }

    void manyPushTest()
    {
        for (int i = 0; i < 50; i++)
            bag->add(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            QCOMPARE(bag->getQuantity(i), 50 - i);
    }

    void removeWithMaxQuantityTest()
    {
        bag->add(value, 10);
        QCOMPARE(bag->getSize(), 1);
        bag->remove(value, 10);
        QVERIFY(!bag->exists(value));
        QCOMPARE(bag->getSize(), 0);
    }

    void removeWithLessThanExistsQuantityTest()
    {
        bag->add(value, 10);
        QCOMPARE(bag->getSize(), 1);
        bag->remove(value, 6);
        QVERIFY(bag->exists(value));
        QCOMPARE(bag->getQuantity(value), 4);
        QCOMPARE(bag->getSize(), 1);
    }

    void removeWithMoreThanExistsQuantityTest()
    {
        bag->add(value, 10);
        QVERIFY_EXCEPTION_THROWN(bag->remove(value, 15), Bag<int>::RemoveNodeWithTooManyQuantity);
    }

    void manyRemoveWithMaxQuantityTest()
    {
        for (int i = 0; i < 50; i++)
            bag->add(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            bag->remove(i, 50 - i);
        QCOMPARE(bag->getSize(), 0);
    }

    void manyRemoveWithLessThanExistsQuantityTest()
    {
        for (int i = 0; i < 50; i++)
            bag->add(i, 60 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            bag->remove(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            QCOMPARE(bag->getQuantity(i), 10);
    }

};
