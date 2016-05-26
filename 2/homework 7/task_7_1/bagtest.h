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
        bag->addNode(value, 1);
        QCOMPARE(bag->getSize(), 1);
        QVERIFY(bag->exists(value));
        QCOMPARE(bag->getQuantity(value), 1);
    }

    void pushElementWithMoteThanOneQuantityTest()
    {
        bag->addNode(value, 11);
        QCOMPARE(bag->getSize(), 1);
        QCOMPARE(bag->getQuantity(value), 11);
    }

    void manyPushTest()
    {
        for (int i = 0; i < 50; i++)
            bag->addNode(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            QCOMPARE(bag->getQuantity(i), 50 - i);
    }

    void removeWithMaxQuantityTest()
    {
        bag->addNode(value, 10);
        QCOMPARE(bag->getSize(), 1);
        bag->removeNode(value, 10);
        QVERIFY(!bag->exists(value));
        QCOMPARE(bag->getSize(), 0);
    }

    void removeWithLessThanExistsQuantityTest()
    {
        bag->addNode(value, 10);
        QCOMPARE(bag->getSize(), 1);
        bag->removeNode(value, 6);
        QVERIFY(bag->exists(value));
        QCOMPARE(bag->getQuantity(value), 4);
        QCOMPARE(bag->getSize(), 1);
    }

    void removeWithMoreThanExistsQuantityTest()
    {
        bag->addNode(value, 10);
        QVERIFY_EXCEPTION_THROWN(bag->removeNode(value, 15), Set<int>::RemoveNodeWithTooManyQuantity);
    }

    void manyRemoveWithMaxQuantityTest()
    {
        for (int i = 0; i < 50; i++)
            bag->addNode(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            bag->removeNode(i, 50 - i);
        QCOMPARE(bag->getSize(), 0);
    }

    void manyRemoveWithLessThanExistsQuantityTest()
    {
        for (int i = 0; i < 50; i++)
            bag->addNode(i, 60 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            bag->removeNode(i, 50 - i);
        QCOMPARE(bag->getSize(), 50);
        for (int i = 0; i < 50; i++)
            QCOMPARE(bag->getQuantity(i), 10);
    }

};
