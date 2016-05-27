#pragma once
#include <algorithm>
#include "sort.h"

using namespace std;
template <typename T>
/*!
 * \brief Класс пузырьковой сортировки
 * Что тут ещё сказать? Асимптотика O(n^2).
 */
class BubbleSort : public Sort<T>
{
public:
    void sort(T *array, int size);
};

template <typename T>
/*!
 * \brief Пузырьковая сортировка
 * \param array Указатель на массив с элементами типа T
 * \param size Размер массива
 * Сортирует массив по возрастанию.
 */
void BubbleSort<T>::sort(T *array, int size)
{
    for (int i = 0; i < size - 1; i++)
           for (int j = i + 1; j < size; j++)
               if (array[i] > array[j])
                   swap(array[i], array[j]);
}
