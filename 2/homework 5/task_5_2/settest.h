#pragma once
#include <QObject>
#include <QTest>

#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
private:
    Set<int> *s;
    int value = 7;
private slots:
    void init()
    {
        s = new Set<int>;
    }

    void cleanup()
    {
        delete s;
    }

    void falseExistsTest()
    {
        QVERIFY(!s->exists(value));
    }

    void addTest()
    {
        s->add(value);
        QVERIFY(s->exists(value));
    }

    void manyAddTest()
    {
        const int quantityOfAdding = 20;
        for (int i = 0; i < quantityOfAdding; i++)
            s->add(i);
        for (int i = 0; i < quantityOfAdding; i++)
            QVERIFY(s->exists(i));
    }

    void removeTest()
    {
        s->add(value);
        s->remove(value);
        QVERIFY(!s->exists(value));
    }

    void falseRemoveTest()
    {
        QVERIFY(!s->remove(value));
    }

    void manyRemoveTest()
    {
        const int quantityOfAdding = 20;
        for (int i = 0; i < quantityOfAdding; i++)
            s->add(i);
        for (int i = 0; i < quantityOfAdding; i++)
            s->remove(i);
        for (int i = 0; i < quantityOfAdding; i++)
            QVERIFY(!s->exists(i));
    }

    void intersectionOfSetsTest()
    {
        Set<int> *secondSet = new Set<int>;
        int const size = 20;
        int firstArray[size];
        int secondArray[size];
        for(int i = 0; i < size; i++)
        {
            firstArray[i] = i;
            secondArray[i] = i - size / 2;
            s->add(firstArray[i]);
            secondSet->add(secondArray[i]);
        }
        Set<int> *resultSet = Set<int>::intersectionOfSets(s, secondSet);
        for(int i = 0; i < size / 2; i++)
            QVERIFY(resultSet->exists(i));
        delete secondSet;
        delete resultSet;
    }

    void mergeOfSetsTest()
    {
        Set<int> *secondSet = new Set<int>;
        int const size = 20;
        int firstArray[size];
        int secondArray[size];
        for(int i = 0; i < size; i++)
        {
            firstArray[i] = i;
            secondArray[i] = i + size / 2;
            s->add(firstArray[i]);
            secondSet->add(secondArray[i]);
        }
        Set<int> *resultSet = Set<int>::mergeOfSets(s, secondSet);
        for(int i = 0; i < size + size / 2; i++)
            QVERIFY(resultSet->exists(i));
        delete secondSet;
        delete resultSet;
    }
};
