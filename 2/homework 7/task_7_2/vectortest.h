#pragma once
#include <QObject>
#include <QtTest>
#include <ctime>
#include <random>

#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    void createRandomCoordinates(const int n)
    {
        srand(time(0));
        for (int i = 0; i < n; i++)
            coordinates.append(rand() % maxValue - maxValue / 2);
    }

private:
    const int maxValue = 100;
    QList<int> coordinates;
private slots:
    void cleanup()
    {
        coordinates.clear();
    }

    void nullVectorTest()
    {
        Vector<int, 42> vector;
        QVERIFY(vector.isNull());
    }

    void coordinateConstructorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        Vector<int, n> vector(coordinates);
        for (int i = 0; i < n; i++)
            QCOMPARE(coordinates.at(i), vector.at(i));
    }

    void isEqualOperatorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        Vector<int, n> vector1(coordinates);
        Vector<int, n> vector2(coordinates);
        QVERIFY(vector1 == vector2);
    }

    void copyConstructorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        Vector<int, n> vector1(coordinates);
        Vector<int, n> vector2(vector1);
        QVERIFY(vector1 == vector2);
    }

    void additionOperatorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        QList<int> coordinates2(coordinates);
        coordinates.clear();
        createRandomCoordinates(n);
        Vector<int, n> vector1(coordinates);
        Vector<int, n> vector2(coordinates2);
        Vector<int, n> resultVector = vector1 + vector2;
        for (int i = 0; i < n; i++)
            QCOMPARE(resultVector.at(i), coordinates.at(i) + coordinates2.at(i));
    }

    void substractionOperatorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        QList<int> coordinates2(coordinates);
        coordinates.clear();
        createRandomCoordinates(n);
        Vector<int, n> vector1(coordinates);
        Vector<int, n> vector2(coordinates2);
        Vector<int, n> resultVector = vector1 - vector2;
        for (int i = 0; i < n; i++)
            QCOMPARE(resultVector.at(i), coordinates.at(i) - coordinates2.at(i));
    }

    void scalarOperatorTest()
    {
        const int n = 42;
        createRandomCoordinates(n);
        QList<int> coordinates2(coordinates);
        coordinates.clear();
        createRandomCoordinates(n);
        Vector<int, n> vector1(coordinates);
        Vector<int, n> vector2(coordinates2);
        int result = 0;
        for (int i = 0; i < n; i++)
            result += coordinates.at(i) * coordinates2.at(i);
        QCOMPARE(result, vector1 * vector2);
    }

};
