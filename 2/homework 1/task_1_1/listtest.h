#pragma once
#include <QObject>
#include <QtTest>

#include "listdoublelinked.h"
#include "listsinglelinked.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    ListTest(bool doubleLinked)
    {
        isDoubleLinked = doubleLinked;
    }
private:
    List* list;
    bool isDoubleLinked; ///< true - ListDoubleLinked, false - ListSigleLinked.
private slots:
    void init()
    {
        if (isDoubleLinked)
            list = new ListDoubleLinked;
        else
            list = new ListSingleLinked;
    }

    void cleanup()
    {
        delete list;
    }

    void addTest()
    {
        QVERIFY(list->length() == 0);
        list->add(10);
        QVERIFY(list->length() == 1);
    }

    void manyAddTest()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        QCOMPARE(list->length(), 100);
    }

    void removeTest()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        QVERIFY(list->remove(1));
        QVERIFY(list->remove(13));
        QVERIFY(list->remove(55));
        QCOMPARE(list->length(), 97);
    }

    void falseRemoveTest()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        QVERIFY(!list->remove(122));
        QVERIFY(!list->remove(-111));
    }
};
