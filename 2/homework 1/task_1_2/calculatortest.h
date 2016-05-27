#pragma once
#include <QObject>
#include <QtTest>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
private slots:
    void someExpressionTest1()
    {
        const char expression[] = "2+2*2";
        QCOMPARE(Calculator::calculate(expression), 6.0);
    }

    void someExpressionTest2()
    {
        const char expression[] = "(2.5+2.5) * 2.3";
        QCOMPARE(Calculator::calculate(expression), 11.5);
    }

    void someExpressionTest3()
    {
        const char expression[] = "(3+7)/2-13*2 + 3*21";
        QCOMPARE(Calculator::calculate(expression), 42.0);
    }
};
