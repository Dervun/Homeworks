#pragma once
#include <QObject>
#include <QtTest>

#include "networkfortest.h"

class LocalAreaNetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit LocalAreaNetworkTest(QObject* parent = 0) : QObject(parent){}
private slots:
    void init()
    {
        FILE* informationFile = fopen("Test_file.txt", "rt");
        testNetwork = new NetworkForTest(informationFile);
        fclose(informationFile);
    }

    void cleanup()
    {
        delete testNetwork;
    }

    void initialStateTest()
    {
        int quantity = testNetwork->getQuantityOfAllComputers();
        QVERIFY2(quantity == 8, "Incorrect file reading");
        QVERIFY2(testNetwork->isInfected(0), "First computer not infected");
        for (int i = 1; i < quantity; i++)
            QVERIFY2(!testNetwork->isInfected(i), "Not first computes was infected");
    }

    void sequenceOfComputerInfectionTest1()
    {
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(1) && testNetwork->isInfected(3), "Not all computers have been infected");
        QVERIFY2(testNetwork->getQuantityOfInfectedComputers() == 3, "Wrong computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(4) && testNetwork->isInfected(5), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(7), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(6), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->allComputersWasInfected(), "Something was wrong");
    }

    void sequenceOfComputerInfectionTest2()
    {
        testNetwork->setInfected(0, false);
        testNetwork->setInfected(5, true);
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(1) && testNetwork->isInfected(7), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(0) && testNetwork->isInfected(6), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->isInfected(2) && testNetwork->isInfected(3), "Not all computers have been infected");
        testNetwork->makeStep();
        QVERIFY2(testNetwork->allComputersWasInfected(), "Something was wrong");
    }

private:
    LocalAreaNetwork* testNetwork;
};
