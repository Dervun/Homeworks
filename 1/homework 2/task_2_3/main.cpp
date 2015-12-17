/*!
 * > Напечатать все представления натурального числа N суммой натуральных слагаемых.
 * > Перестановка слагаемых нового способа не дает.
 */
#include <cstdio>

void decomposition(int *a, int n, int k, int i)
{
    if (n < 0)
    return;
    else if (n == 0)
    {
        for (int j = 0; j < i; j++)
              printf("%d ", a[j]);
        printf("\n");
    }
    else
    {
        if (n >= k)
        {
            a[i] = k;
            decomposition(a, n - k, k, i + 1);
        }
        if (k > 1)
            decomposition(a, n, k - 1, i);
    }
    return;
}

main()
{
    int a[100];
    int number = 0;
    int i = 0;
    printf("Enter N < 30:\n");
    scanf("%d", &number);
    for (i = 0; i < number; i++)
        a[i] = 0;
    decomposition(a, number, number, 0);
}
