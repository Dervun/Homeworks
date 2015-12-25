/*!
 * > Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).
 */
#include "qsort.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

main()
{
    int lengthOfArray = 0;
    printf("Enter length of array:\n");
    scanf("%d", &lengthOfArray);
    int *array = new int[lengthOfArray];
    srand (time(NULL));
    for (int i = 0; i < lengthOfArray; i++)
        array[i] = rand() % 100;
    printf("Array:\n");
    for (int k = 0; k < lengthOfArray; k++)
        printf("%d ", array[k]);
    qsort(array, 0, lengthOfArray - 1);
    bool hasFound = false;
    for (int j = lengthOfArray - 1; j > 0; j--)
    {
        if (array[j] == array[j - 1])
        {
            printf("\nResult: %d", array[j]);
            hasFound = true;
            break;
        }
    }
    if (!hasFound)
        printf("\nNot found :(\n");
    delete []array;
}
