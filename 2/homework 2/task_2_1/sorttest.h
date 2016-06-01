#pragma once
#include <QObject>
#include <QtTest>

#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"

class SortTest : public QObject
{
    Q_OBJECT
public:
    SortTest(int selectTypeOfSort)
    {
        typeOfSort = selectTypeOfSort;
    }
private:
    int typeOfSort = 0; ///< Тип сортировки: 0 - быстрая, 1 - кучей, 2 - пузырёк.
    Sort<int>* s;

    bool isSorted(int *array, int length)
    {
        for (int i = 0; i < length - 1; i++)
            if (array[i] > array[i + 1])
                return false;
        return true;
    }

private slots:
    void init()
    {
        if (typeOfSort == 0)
            s = new QuickSort<int>;
        else if (typeOfSort == 1)
            s = new HeapSort<int>;
        else if (typeOfSort == 2)
            s = new BubbleSort<int>;
        else
        {
            QFAIL("Don't valid type of sort!");
            s = new QuickSort<int>;
        }
    }

    void cleanup()
    {
        delete s;
    }

    void sortArrayWith100Length()
    {
        int length= 100;
        int *array = new int[length];
        s->sort(array, length);
        QVERIFY(isSorted(array, length));
    }

    void sortArrayWith500Length()
    {
        int length= 500;
        int *array = new int[length];
        s->sort(array, length);
        QVERIFY(isSorted(array, length));
    }

    void sortArrayWith1000Length()
    {
        int length= 1000;
        int *array = new int[length];
        s->sort(array, length);
        QVERIFY(isSorted(array, length));
    }

    void sortArrayWith9999Length()
    {
        int length= 9999;
        int *array = new int[length];
        s->sort(array, length);
        QVERIFY(isSorted(array, length));
    }


};
