#pragma once

#include <QObject>
#include <QTest>
#include <string.h>

#include "calculator.h"

class TreeTest : public QObject
{
    Q_OBJECT
private:
    Calculator *expression;
    FILE *inputStream;
    FILE *outputStream;
    void putStringAndOpenFileForRead(const char *string)
    {
        fputs(string, inputStream);
        fclose(inputStream);
        inputStream = fopen("inputTest.txt", "rt");
    }
private slots:
    void init()
    {
        inputStream = fopen("inputTest.txt", "wt");
        outputStream = fopen("outputTest.txt", "wt");
    }

    void cleanup()
    {
        fclose(inputStream);
        fclose(outputStream);
    }

    void calculateAdditionTest()
    {
        const char string[] = "(+ 3 7)";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        QCOMPARE(expression->calculate(), 10);
    }

    void calculateSubtractionTest()
    {
        const char string[] = "(- 5 11)";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        QCOMPARE(expression->calculate(), -6);
    }

    void calculateMultiplicationTest()
    {
        const char string[] = "(* 7 8)";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        QCOMPARE(expression->calculate(), 56);
    }

    void calculateDivisionTest()
    {
        const char string[] = "(/ 25 10)";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        QCOMPARE(expression->calculate(), 2);
    }

    void calculateSomeExpressionTest()
    {
        const char string[] = "(* (+ 13 -6) (+ (- 13 10) 3))";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        QCOMPARE(expression->calculate(), 42);
    }

    void printSmallExpressionTest()
    {
        const char string[] = "(* 7 8)";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        expression->print();
        fclose(outputStream);
        outputStream = fopen("outputTest.txt", "rt");
        char actual[1000];
        fgets(actual, 1000, outputStream);
        QVERIFY(strcmp(actual, string) == 0);
    }

    void printBigExpressionTest()
    {
        const char string[] = "(* (+ 13 -6) (+ (- 13 10) 3))";
        putStringAndOpenFileForRead(string);
        expression = new Calculator(inputStream, outputStream);
        expression->print();
        fclose(outputStream);
        outputStream = fopen("outputTest.txt", "rt");
        char actual[1000];
        fgets(actual, 1000, outputStream);
        QVERIFY(strcmp(actual, string) == 0);
    }

};
