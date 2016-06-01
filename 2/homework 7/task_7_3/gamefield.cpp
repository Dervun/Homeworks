#include "gamefield.h"

GameField::GameField(const int size, const int lengthToWin, QObject *parent):
    QObject(parent),
    lengthToWin(lengthToWin),
    size(size)
{
    field = new Cell*[size];
    for (int i = 0; i < size; i++)
    {
        field[i] = new Cell[size];
        for (int j = 0; j < size; j++)
            field[i][j] = empty;
    }
}

GameField::~GameField()
{
    for (int i = 0; i < size; i++)
        delete [] field[i];
    delete [] field;
}

void GameField::cellChanged(int x, int y, bool isNull)
{
    numberOfClickedButtons++;
    Cell currentState = isNull ? O : X;
    field[x][y] = currentState;
    if (checkHorizontal(currentState, x, y) >= lengthToWin ||
        checkVertical(currentState, x, y) >= lengthToWin ||
        checkMainDiagonal(currentState, x, y) >= lengthToWin ||
        checkMinorDiagonal(currentState, x, y) >= lengthToWin)
    {
        emit winner(QString("Player #") + (isNull ? "2" : "1") + " wins!");
        return;
    }
    if (numberOfClickedButtons == size * size)
    {
        emit winner("Game field is full, start new game!");
    }
}

void GameField::clear()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            field[i][j] = empty;
    numberOfClickedButtons = 0;
}

int GameField::checkHorizontal(Cell currentState, int x, int y)
{
    int currentCount = 1;
    int i = y - 1;
    while (i >= 0 && field[x][i] == currentState)
    {
        currentCount++;
        i--;
    }
    i = y + 1;
    while (i < size && field[x][i] == currentState)
    {
        currentCount++;
        i++;
    }
    return currentCount;
}

int GameField::checkVertical(Cell currentState, int x, int y)
{
    int currentCount = 1;
    int i = x - 1;
    while (i >= 0 && field[i][y] == currentState)
    {
        currentCount++;
        i--;
    }
    i = x + 1;
    while (i < size && field[i][y] == currentState)
    {
        currentCount++;
        i++;
    }
    return currentCount;
}

int GameField::checkMainDiagonal(Cell currentState, int x, int y)
{
    int currentCount = 1;
    int i = x - 1;
    int j = y + 1;
    while (i >= 0  && j < size && field[i][j] == currentState)
    {
        currentCount++;
        i--;
        j++;
    }
    i = x + 1;
    j = y - 1;
    while (i < size && j >= 0 && field[i][j] == currentState)
    {
        currentCount++;
        i++;
        j--;
    }
    return currentCount;
}

int GameField::checkMinorDiagonal(Cell currentState, int x, int y)
{
    int currentCount = 1;
    int i = x - 1;
    int j = y - 1;
    while (i >= 0  && j >= 0 && field[i][j] == currentState)
    {
        currentCount++;
        i--;
        j--;
    }
    i = x + 1;
    j = y + 1;
    while (i < size && j < size && field[i][j] == currentState)
    {
        currentCount++;
        i++;
        j++;
    }
    return currentCount;
}
