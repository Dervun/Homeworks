#pragma once
#include <QObject>
#include <QtTest>

#include "computer.h"

class ComputerTest : public QObject
{
    Q_OBJECT
public:
    explicit ComputerTest(QObject* parent = 0) : QObject(parent){}
private slots:

    void linuxInfectionRate()
    {
        computer = new Computer(Linux);
        double result = averageFrequencyOfInfected(10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected - %g, result - %g\n", computer->getProbabitityOfInfection(), result);
        delete computer;
    }

    void windowsInfectionRate()
    {
        computer = new Computer(Windows);
        double result = averageFrequencyOfInfected(10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected - %g, result - %g\n", computer->getProbabitityOfInfection(), result);
        delete computer;
    }

    void macInfectionRate()
    {
        computer = new Computer(Mac);
        double result = averageFrequencyOfInfected(10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected - %g, result - %g\n", computer->getProbabitityOfInfection(), result);
        delete computer;
    }

private:
    Computer* computer;
    double averageFrequencyOfInfected(int quantityOfAttempts)
    {
        int quantityOfInfected = 0;
        for (int i = 0; i < quantityOfAttempts; i++)
        {
            if (computer->tryToInfect())
                quantityOfInfected++;
        }
        return (double) quantityOfInfected / quantityOfAttempts;
    }
};
