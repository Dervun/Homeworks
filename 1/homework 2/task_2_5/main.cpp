/*!
 * > Реализовать алгоритм пирамидальной сортировки.
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "heapSort.h"

main()
{
    int lengthOfArray = 0;
    printf("Enter length of array:\n");
    scanf("%d", &lengthOfArray);
    int *array = new int[lengthOfArray];
    srand (time(NULL));
    for (int i = 0; i < lengthOfArray; i++)
        array[i] = rand() % 100;
    printf("Before:\n");
    for (int j = 0; j < lengthOfArray; j++)
        printf("%d ", array[j]);
    heapSort(array, lengthOfArray);
    printf("\nAfter:\n");
    for (int k = 0; k < lengthOfArray; k++)
        printf("%d ", array[k]);
    delete []array;
}
