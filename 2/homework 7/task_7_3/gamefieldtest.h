#pragma once
#include <QtTest>

#include "gamefield.h"

class GameFieldTest : public QObject
{
    Q_OBJECT
public slots:
    void setMessage(const QString &m)
    {
        message = m;
    }

private slots:
    void init()
    {
        field = new GameField(3, 3);
        connect(field, &GameField::winner,
                this, &GameFieldTest::setMessage);
    }

    void cleanup()
    {
        delete field;
    }

    void testHorizontalLine()
    {
        field->cellChanged(1, 1, false);
        field->cellChanged(2, 1, true);
        field->cellChanged(1, 0, false);
        field->cellChanged(2, 0, true);
        field->cellChanged(1, 2, false);
        QCOMPARE(message, QString("Player #1 wins!"));
    }
    void testVerticalLine()
    {
        field->cellChanged(1, 1, false);
        field->cellChanged(2, 2, true);
        field->cellChanged(0, 1, false);
        field->cellChanged(1, 2, true);
        field->cellChanged(0, 0, false);
        field->cellChanged(0, 2, true);
        QCOMPARE(message, QString("Player #2 wins!"));
    }
    void testDiagonalLine()
    {
        field->cellChanged(0, 2, true);
        field->cellChanged(1, 1, false);
        field->cellChanged(2, 1, true);
        field->cellChanged(0, 0, false);
        field->cellChanged(1, 0, true);
        field->cellChanged(2, 2, false);
        QCOMPARE(message, QString("Player #1 wins!"));
    }
    void testDraw()
    {
        field->cellChanged(1, 1, false);
        field->cellChanged(0, 0, true);
        field->cellChanged(2, 0, false);
        field->cellChanged(0, 2, true);
        field->cellChanged(0, 1, false);
        field->cellChanged(2, 1, true);
        field->cellChanged(1, 2, false);
        field->cellChanged(1, 0, true);
        field->cellChanged(2, 2, false);
        QCOMPARE(message, QString("Game field is full, start new game!"));
    }

private:
    QString message = "";
    GameField *field;
};
