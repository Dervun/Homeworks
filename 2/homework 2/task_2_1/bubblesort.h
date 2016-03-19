#pragma once
#include <algorithm>

#include "sort.h"

using namespace std;

template <typename T>
class BubbleSort : public Sort<T>
{
    void sort(T *array, int size)
    {
        for (int i = 0; i < size - 1; i++)
               for (int j = i + 1; j < size; j++)
                   if (array[i] > array[j])
                       swap(array[i], array[j]);
    }
};
