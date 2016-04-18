/*!
 * Создать интерфейс сортировщика, принимающего массив элементов и выполняющего над ним сортировку.
 * На его основе создать несколько классов, реализующих произвольные (разные) алгоритмы сортировки.
 * В этой программе есть пузырьковая сортировка, пирамидальная и быстрая.
 */
#include <cstdio>
#include <string.h>

#include "bubblesort.h"
#include "heapsort.h"
#include "quicksort.h"

int main()
{
    printf("Please, enter length of array (less than 100):\n");
    int lengthOfArray = 0;
    scanf("%d", &lengthOfArray);
    long double* array = new long double[lengthOfArray];
    printf("Enter elements of array:\n");
    for (int i = 0; i < lengthOfArray; i++)
        scanf("%Lg", &array[i]);
    Sort<long double>* sorter = new QuickSort<long double>;
    sorter->sort(array, lengthOfArray);
    delete sorter;
    printf("Sorted array:\n");
    for (int i = 0; i < lengthOfArray; i++)
        printf("%Lg ", array[i]);
    printf("\nEnd :)\n");
    return 0;
}

