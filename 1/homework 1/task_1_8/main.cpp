/*!
 * > Реализовать подсчет факториала (рекурсивно и итеративно).
 */
#include <stdio.h>

int factorialRecursive (int k)
{
    return k > 1 ? k * factorialRecursive (k - 1) : 1;
}

int factorialIterative (int m)
{
    int result = 1;
    for (int i = m; i >= 2; i--)
        result *= i;
    return result;
}

int main()
{
    int n = 0;
    printf("Enter n!\n");
    scanf("%d!", &n);
    if (n >= 0)
    {
        int resultIterative = factorialIterative(n);
        printf("%d! = %d\n", n, resultIterative);
        int resultRecursive = factorialRecursive(n);
        printf("%d! = %d\n", n, resultRecursive);
    }
    else
        printf("Error. Please, enter positiv n");
    return 0;
}
