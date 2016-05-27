#pragma once
#include <QObject>
#include <QTest>

#include "uniquelist.h"

class UniqueListTest : public QObject
{
    Q_OBJECT
private:
    UniqueList* l;
private slots:
    void init()
    {
        l = new UniqueList;
    }

    void cleanup()
    {
        delete l;
    }

    void addTest()
    {
        l->add(3);
        QCOMPARE(l->length(), 1);
        QVERIFY(l->exists(3));
    }
    void manyAddTest()
    {
        for (int i = 0; i < 50; i++)
            l->add(i);
        for (int i = 49; i >= 0; i--)
            QVERIFY(l->exists(i));
        QCOMPARE(l->length(), 50);
    }

    void removeTest()
    {
        l->add(5);
        l->remove(5);  // <- Здесь проблема
        QVERIFY(!l->exists(5));
        QCOMPARE(l->length(), 0);
    }

    void manyRemoveTest()
    {
        for (int i = 0; i < 50; i++)
            l->add(i);
        for (int i = 0; i < 50; i++)
            l->remove(i);
        for (int i = 49; i >= 0; i--)
            QVERIFY(!l->exists(i));
        QCOMPARE(l->length(), 0);
    }

    void addExistingElements()
    {
        for (int i = 0; i < 50; i++)
            l->add(i);
        QVERIFY_EXCEPTION_THROWN(l->add(42), UniqueList::AlreadyExistingElementExeption);
    }

    void removeNotExistsElementTest()
    {
        for (int i = 0; i < 50; i++)
            l->add(i);
        QVERIFY_EXCEPTION_THROWN(l->remove(111), UniqueList::RemoveNotExistsElementExeption);
    }
};
