#pragma once
#include <string.h>
#include <algorithm>

#include "sort.h"

using namespace std;

template <typename T>
/*!
 * \brief Быстрая сортировка
 * Классная вещь, работает в среднем за n*log(n)
 */
class QuickSort : public Sort<T>
{
public:
    /*!
     * \brief Основная функция, которая запускает рекурсивную функцию сортировки.
     * \param array Массив, который надо сортировать
     * \param size Размер данного массива
     */
    void sort(T* array, int size)
    {
        qsort(array, 0, size - 1);
    }
private:
    void qsort(T* a, int primordialLeft, int primordialRight);
};

template <typename T>
/*!
 * \brief Рекурсивная функция сортировки
 * \param a Массив, который надо сортировать
 * \param primordialLeft Левая граница сортировки
 * \param primordialRight Правая граница сортировки
 * Запускает себя от одной и другой половины массива.
 */
void QuickSort<T>::qsort(T* a, int primordialLeft, int primordialRight)
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

template <>
/*!
 * \brief Класс быстрой сортировки для массива строк
 */
class QuickSort<char*> : public Sort<char*>
{
public:
    /*!
     * \brief Та же быстрая сортировка, только для строк
     * \param array Массив, который надо сортировать
     * \param size Размер данного массива
     */
    void sort(char** array, int size)
    {
        qsort(array, 0, size - 1);
    }
private:
    void qsort(char** a, int primordialLeft, int primordialRight);
};

/*!
 * \brief Рекурсивная функция сортировки массива строк
 * \param a Массив, который надо сортировать
 * \param primordialLeft Левая граница сортировки
 * \param primordialRight Правая граница сортировки
 * Запускает себя от одной и другой половины массива.
 */
void QuickSort<char*>::qsort(char** a, int primordialLeft, int primordialRight)
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
