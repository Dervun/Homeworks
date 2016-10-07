#pragma once
#include <QObject>
#include <QtTest>

#include "computer.h"

/*!
 * \brief Класс для тестирования класса Computer
 * Тестирование производится на соответствие реальной частоты заражения компьютера той, которая у него указана.
 */
class ComputerTest : public QObject
{
    Q_OBJECT
public:
    explicit ComputerTest(QObject* parent = 0) : QObject(parent){}
private slots:

    void linuxInfectionRate()
    {
        double result = averageFrequencyOfInfected(Linux, 10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected: %g; result: %g\n", computer->getProbabitityOfInfection(), result);
    }

    void windowsInfectionRate()
    {
        double result = averageFrequencyOfInfected(Windows, 10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected: %g; result: %g\n", computer->getProbabitityOfInfection(), result);
    }

    void macInfectionRate()
    {
        double result = averageFrequencyOfInfected(Mac, 10000);
        QVERIFY(abs(result - computer->getProbabitityOfInfection()) < 0.1);
        printf("Expected: %g; result: %g\n", computer->getProbabitityOfInfection(), result);
    }

private:
    Computer* computer;
    double averageFrequencyOfInfected(TypeOfOS type, int quantityOfAttempts)
    {
        computer = new Computer(type);
        int quantityOfInfected = 0;
        for (int i = 0; i < quantityOfAttempts; i++)
        {
            if (computer->tryToInfect())
                quantityOfInfected++;
            computer->setInfected(false);
        }
        delete computer;
        return (double) quantityOfInfected / quantityOfAttempts;
    }
};
