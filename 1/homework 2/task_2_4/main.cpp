/*!
 * > Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают n.
 */
#include <cstdio>
#include "qsort.h"

bool relativePrime(int a, int b)
{
    while (a != b)
        {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
    return (a == 1);
}

main()
{
    int n = 0;
    printf("Enter N:\n");
    scanf("%d", &n);
    Fraction array[n * n / 2];
    int k = 0;
    for (int i = n; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (relativePrime(j, i))
            {
                array[k].numerator = j;
                array[k].denominator = i;
                k++;
            }
        }
    }
    printf("Result:\n");
    k--;
    float arrayOfValues[k + 1];
    for (int m = 0; m < k + 1; m++)
        arrayOfValues[m] = (double) array[m].numerator / array[m].denominator;
    qsort(arrayOfValues, 0, k, array);
    for (int q = 0; q < k + 1; q++)
        printf("%d/%d; ", array[q].numerator, array[q].denominator);
}
