#pragma once
#include <algorithm>
#include "sort.h"
using namespace std;

template <typename T>
/*!
 * \brief Пирамидальная сортировка
 * Она же сортировка кучей.
 * Алгоритм сортировки, работающий в худшем, в среднем и в лучшем случае (то есть гарантированно) за Θ(n log n) операций при сортировке n элементов.
 * Количество применяемой служебной памяти не зависит от размера массива (то есть, O(1)).
 */
class HeapSort : public Sort<T>
{
public:
    void sort(T *array, int size);
private:
    static void shiftDown(T* a, int currentIndex, int numberOfElements);
    static void heapify(T* array, int numberOfElements);
};

template <typename T>
/*!
 * \brief Пирамидальная сортировка массива
 * \param array Массив
 * \param size Размер массива
 * Собственно, это основная функция. Сортирует массив по возрастанию.
 */
void HeapSort<T>::sort(T *array, int size)
{
    heapify(array, size);
    for (int numberOfUnsortedElements = size - 1; numberOfUnsortedElements >= 1; numberOfUnsortedElements--)
    {
        swap(array[numberOfUnsortedElements], array[0]);
        shiftDown(array, 0, numberOfUnsortedElements);
    }
}

template <typename T>
/*!
 * \brief Вспомогательная функция для сортировки
 * \param a Указатель на массив
 * \param currentIndex Текущий индекс
 * \param numberOfElements Количество ещё не отсортированных элементов
 */
void HeapSort<T>::shiftDown(T *a, int currentIndex, int numberOfElements)
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

template <typename T>
/*!
 * \brief Вспомогательная функция для сортировки
 * \param array Указатель на массив для сортировки
 * \param numberOfElements Количество ещё не отсортированных элементов
 */
void HeapSort<T>::heapify(T *array, int numberOfElements)
{
    for (int currentIndex = numberOfElements - 1; currentIndex >= 0; currentIndex--)
        shiftDown(array, currentIndex, numberOfElements);
}
