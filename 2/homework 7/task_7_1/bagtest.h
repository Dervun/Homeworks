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

    void intersectionQuantityTest()
    {
        Bag<int> *secondBag = new Bag<int>;
        bag->add(value, 10);
        secondBag->add(value, 3);
        Bag<int> *newBag = Bag<int>::intersection(bag, secondBag);
        QCOMPARE(newBag->getQuantity(value), 3);
    }

    void intersectionOfBagsTest()
    {
        Bag<int> *secondBag = new Bag<int>;
        int const size = 20;
        int firstArray[size];
        int secondArray[size];
        for(int i = 0; i < size; i++)
        {
            firstArray[i] = i;
            secondArray[i] = i - size / 2;
            bag->add(firstArray[i], i + 1);
            secondBag->add(secondArray[i], i + 1);
        }
        Bag<int> *resultBag = Bag<int>::intersection(bag, secondBag);
        for(int i = 0; i < size / 2; i++)
            QVERIFY(resultBag->exists(i));
        delete secondBag;
        delete resultBag;
    }

    void mergeQuantityTest()
    {
        Bag<int> *secondBag = new Bag<int>;
        bag->add(value, 10);
        secondBag->add(value, 3);
        Bag<int> *newBag = Bag<int>::merge(bag, secondBag);
        QCOMPARE(newBag->getQuantity(value), 10);
    }

    void mergeOfBagsTest()
    {
        Bag<int> *secondBag = new Bag<int>;
        int const size = 20;
        int firstArray[size];
        int secondArray[size];
        for(int i = 0; i < size; i++)
        {
            firstArray[i] = i;
            secondArray[i] = i + size / 2;
            bag->add(firstArray[i], i + 1);
            secondBag->add(secondArray[i], i + 1);
        }
        Bag<int> *resultBag = Bag<int>::merge(bag, secondBag);
        for(int i = 0; i < size + size / 2; i++)
            QVERIFY(resultBag->exists(i));
        delete secondBag;
        delete resultBag;
    }

};
