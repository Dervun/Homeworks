/*!
 * > Дан массив целых чисел x[1]...x[m+n], рассматриваемый как соединение двух его отрезков: начала x[1]...x[m] длины m и конца x[m+1]...x[m+n] длины n.
 * > Не используя дополнительных массивов, переставить начало и конец.
 */
#include <stdio.h>
#include <algorithm>

using namespace std;

void turn(int *arr, int left, int right)
{
    for (int j = left; j < left + (right - left) / 2; j++)
        swap(arr[j], arr[right + left - j]);
}

main()
{
    printf("Enter m, n (e.g. '5, 8'):\n");
    int m = 0;
    int n = 0;
    scanf("%d, %d", &m, &n);
    int arraySize = m + n;
    int array[arraySize];
    for (int i = 0; i < arraySize; i++)
        array[i] = i;
    printf("Before:\n");
    for (int i = 0; i < arraySize - 1; i++)
        printf("%d:", array[i]);
    printf("%d\n", array[arraySize - 1]);
    turn(array, 0, m - 1);
    turn(array, m, arraySize - 1);
    turn(array, 0, arraySize - 1);
    printf("After:\n");
    for (int i = 0; i < arraySize - 1; i++)
        printf("%d:", array[i]);
    printf("%d\n", array[m+n-1]);
}
