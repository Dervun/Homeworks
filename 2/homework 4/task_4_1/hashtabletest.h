#pragma once
#include <ctime>
#include <QObject>
#include <QtTest>

#include "hashtable.h"
using namespace std;

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject* parent = 0) : QObject(parent){}
private slots:
    void init()
    {
        t = new HashTable;
    }

    void cleanup()
    {
        delete t;
    }

    void addTest()
    {
        t->addToTable("Hellow, world!");
        QVERIFY(t->getQuantityOfStrings() == 1);
    }

    void manyAddTest()
    {
        srand(time(0));
        for (int i = 0; i < 10000; i++)
        {
            char buffer[21];
            for (int j = 0; j < 20; j++)
                buffer[j] = (char) (rand() % 127);
            buffer[20] = '\0';
            QString string(buffer);
            t->addToTable(string);
        }
    }

    void removeTest()
    {
        const QString string("Sunday");
        t->addToTable(string);
        QVERIFY(t->remove(string));
        QVERIFY(t->getQuantityOfStrings() == 0);
    }

    void falseRemoveTest()
    {
        const QString string("Sunday");
        QVERIFY(!t->remove(string));
    }

    void loadFactorTest()
    {
        QVERIFY(t->getLoadFactor() == 0);
        const QString string("Sunday");
        t->addToTable(string);
        QVERIFY(t->getLoadFactor() > 0);
        t->remove(string);
        QVERIFY(t->getLoadFactor() == 0);
    }

    void searchTest()
    {
        const QString string("Sunday");
        t->addToTable(string);
        QVERIFY(t->search(string));
    }

    void falseSearchTest()
    {
        const QString string("Sunday");
        QVERIFY(!t->search(string));
    }

    void quantityOfConflicts()
    {
        delete t;
        t = new HashTable(1);
        QVERIFY(t->quantityOfConflicts() == 0);
        const QString string1("Sunday");
        t->addToTable(string1);
        QVERIFY(t->quantityOfConflicts() == 0);
        const QString string2("Monday");
        t->addToTable(string2);
        QVERIFY(t->quantityOfConflicts() == 1);
    }

    void maxLengthOfListTest()
    {
        delete t;
        t = new HashTable(1);
        QVERIFY(t->maxLengthOfList() == 0);
        const QString string1("Sunday");
        t->addToTable(string1);
        QVERIFY(t->maxLengthOfList() == 1);
        const QString string2("Monday");
        t->addToTable(string1);
        QVERIFY(t->maxLengthOfList() == 1);
        t->addToTable(string2);
        QVERIFY(t->maxLengthOfList() == 2);
    }

    void hardTest()
    {
        FILE* stream = fopen("Harry_Potter_all_books.txt", "rt");
        if (!stream)
        {
            QWARN("File was not found!");
            return;
        }
        char buffer[1000];
        while (!feof(stream))
        {
            fscanf(stream, "%s", buffer);
            QString string(buffer);
            int length = string.length();
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                if (string[i].isLetter())
                {
                    string[k] = string[i].toLower();
                    k++;
                }
            }
            if (k > 0)
                t->addToTable(string);
        }
        fclose(stream);
        QVERIFY(t->getLoadFactor() < 3);
    }

private:
    HashTable* t;
};
