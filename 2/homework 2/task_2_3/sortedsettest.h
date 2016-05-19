#pragma once
#include <QObject>
#include <QtTest>

#include "sortedset.h"

class SortedSetTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedSetTest(QObject* parent = 0) : QObject(parent){}
private slots:
    void init()
    {
        set = new SortedSet;
    }

    void cleanup()
    {
        delete set;
    }

    void pushTest()
    {
        ListComparable* newList = createListWithSpecificLength(10);
        set->addTreeNode(newList);
        delete newList;
        QVERIFY(set->treeHeight() == 1);
    }

    void searchTest()
    {
        ListComparable* newList = createListWithSpecificLength(5);
        set->addTreeNode(newList);
        delete newList;
        QVERIFY(set->search(newList) != nullptr);
    }

    void manyPushTest()
    {
        for (int i = 1; i < 15; i++)
        {
            ListComparable* newList = createListWithSpecificLength(i);
            set->addTreeNode(newList);
            delete newList;
        }
        QCOMPARE(set->treeHeight(), 4);
    }

    void searchAfterManyPushTest()
    {
        for (int i = 1; i < 15; i++)
        {
            ListComparable* newList = createListWithSpecificLength(i);
            set->addTreeNode(newList);
            delete newList;
        }
        ListComparable* newList = createListWithSpecificLength(5);
        QVERIFY((*(set->search(newList)))->value->length() == 5);
        delete newList;
        newList = createListWithSpecificLength(3);
        QVERIFY((*(set->search(newList)))->value->length() == 3);
        delete newList;
        newList = createListWithSpecificLength(11);
        QVERIFY((*(set->search(newList)))->value->length() == 11);
        delete newList;
    }
    
    void removeTest()
    {
        ListComparable* newList = createListWithSpecificLength(10);
        set->addTreeNode(newList);
        QVERIFY(set->removeTreeNode(newList));
        QVERIFY(set->treeHeight() == 0);
        delete newList;
    }

    void manyPushAndSomeRemoveTest()
    {
        for (int i = 1; i < 15; i++)
        {
            ListComparable* newList = createListWithSpecificLength(i);
            set->addTreeNode(newList);
            delete newList;
        }
        ListComparable* listForRemove = createListWithSpecificLength(5);
        QVERIFY(set->removeTreeNode(listForRemove));
        delete listForRemove;
        listForRemove = createListWithSpecificLength(7);
        QVERIFY(set->removeTreeNode(listForRemove));
        delete listForRemove;
        listForRemove = createListWithSpecificLength(13);
        QVERIFY(set->removeTreeNode(listForRemove));
        delete listForRemove;
    }

    void falseRemoveTest()
    {
        for (int i = 1; i < 15; i++)
        {
            ListComparable* newList = createListWithSpecificLength(i);
            set->addTreeNode(newList);
            delete newList;
        }
        ListComparable* listForRemove = createListWithSpecificLength(20);
        QVERIFY(!set->removeTreeNode(listForRemove));
        delete listForRemove;
        listForRemove = createListWithSpecificLength(33);
        QVERIFY(!set->removeTreeNode(listForRemove));
        delete listForRemove;
    }

private:
    SortedSet* set;
    ListComparable* createListWithSpecificLength(int length);
};
