#pragma once
#include <algorithm>
#include "sort.h"
using namespace std;

template <typename T>
class HeapSort : public Sort<T>
{
    void sort(T *array, int size)
    {
        heapify(array, size);
        for (int numberOfUnsortedElements = size - 1; numberOfUnsortedElements >= 1; numberOfUnsortedElements--)
        {
            swap(array[numberOfUnsortedElements], array[0]);
            siftDown(array, 0, numberOfUnsortedElements);
        }
    }
private:
    void siftDown(T* a, int currentIndex, int numberOfElements)
    {
        int maxChild = 0;
        int leftChild = currentIndex * 2 + 1;
        int rightChild = currentIndex * 2 + 2;
        while (leftChild < numberOfElements)
        {
            if (leftChild == numberOfElements - 1)
                maxChild = leftChild;
            else if (a[leftChild] > a[rightChild])
                maxChild = leftChild;
            else
                maxChild = rightChild;
            if (a[currentIndex] < a[maxChild])
            {
                swap(a[currentIndex], a[maxChild]);
                currentIndex = maxChild;
                leftChild = currentIndex * 2 + 1;
                rightChild = currentIndex * 2 + 2;
            }
            else
                return;
        }
    }
    void heapify(T* array, int numberOfElements)
    {
        for (int currentIndex = numberOfElements - 1; currentIndex >= 0; currentIndex--)
            siftDown(array, currentIndex, numberOfElements);
    }
};
