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
        s->addTreeNode(value);
        QVERIFY(s->exists(value));
    }

    void manyAddTest()
    {
        const int quantityOfAdding = 20;
        for (int i = 0; i < quantityOfAdding; i++)
            s->addTreeNode(i);
        for (int i = 0; i < quantityOfAdding; i++)
            QVERIFY(s->exists(i));
    }

    void removeTest()
    {
        s->addTreeNode(value);
        s->removeTreeNode(value);
        QVERIFY(!s->exists(value));
    }

    void falseRemoveTest()
    {
        QVERIFY(!s->removeTreeNode(value));
    }

    void manyRemoveTest()
    {
        const int quantityOfAdding = 20;
        for (int i = 0; i < quantityOfAdding; i++)
            s->addTreeNode(i);
        for (int i = 0; i < quantityOfAdding; i++)
            s->removeTreeNode(i);
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
            s->addTreeNode(firstArray[i]);
            secondSet->addTreeNode(secondArray[i]);
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
            s->addTreeNode(firstArray[i]);
            secondSet->addTreeNode(secondArray[i]);
        }
        Set<int> *resultSet = Set<int>::mergeOfSets(s, secondSet);
        for(int i = 0; i < size + size / 2; i++)
            QVERIFY(resultSet->exists(i));
        delete secondSet;
        delete resultSet;
    }
};
