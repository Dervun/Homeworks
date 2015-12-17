/*!
 * > Реализовать быструю сортировку (в рекурсивном варианте).
 */
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void qsort(int primordialLeft, int primordialRight, int a[])
{
    int left = primordialLeft;
    int right = primordialRight;
    int median = a[(left + right) / 2];
    while (left < right)
    {
        while ((a[left] < median) && (left <= right))
            left++;
        while ((a[right] > median) && (right >= left))
            right--;
        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    if (right > primordialLeft)
        qsort(primordialLeft, right, a);
    if (left < primordialRight)
        qsort(left, primordialRight, a);
}

main()
{
    int lengthOfArray = 0;
    printf("Enter length of your array:\n");
    scanf("%d", &lengthOfArray);
    int array[lengthOfArray];
    srand (time(NULL));                          // инициализация функции rand значением функции time
    for (int i = 0; i < lengthOfArray; i++)
        array[i] = rand() % 100;
    printf("Before:\n");
    for (int j = 0; j < lengthOfArray; j++)
        printf(":%d", array[j]);
    qsort(0, lengthOfArray - 1, array);
    printf("\nAfter:\n");
    for (int k = 0; k < lengthOfArray; k++)
        printf(":%d", array[k]);
}
