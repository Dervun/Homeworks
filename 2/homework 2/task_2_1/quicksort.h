#pragma once
#include <string.h>
#include <algorithm>

#include "sort.h"

using namespace std;

template <typename T>
class QuickSort : public Sort<T>
{
public:
    void sort(T* array, int size)
    {
        qsort(array, 0, size - 1);
    }
private:
    void qsort(T* a, int primordialLeft, int primordialRight)
    {
        int left = primordialLeft;
        int right = primordialRight;
        T median = a[(left + right) / 2];
        while (left < right)
        {
            while (a[left] < median && left <= right)
                left++;
            while (a[right] > median && right >= left)
                right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }
        if (right > primordialLeft)
            qsort(a, primordialLeft, right);
        if (left < primordialRight)
            qsort(a, left, primordialRight);
    }
};

template <>
class QuickSort<char*> : public Sort<char*>
{
public:
    void sort(char** array, int size)
    {
        qsort(array, 0, size - 1);
    }
private:
    void qsort(char** a, int primordialLeft, int primordialRight)
    {
        int left = primordialLeft;
        int right = primordialRight;
        char* median = a[(left + right) / 2];
        while (left < right)
        {
            while (strcmp(a[left], median) < 0 && left <= right)
                left++;
            while (strcmp(a[right], median) > 0 && right >= left)
                right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }
        if (right > primordialLeft)
            qsort(a, primordialLeft, right);
        if (left < primordialRight)
            qsort(a, left, primordialRight);
    }
};
