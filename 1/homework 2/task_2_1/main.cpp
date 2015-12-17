#include <stdio.h>

long long fibonacciRecursive (int i)
{
    return (i == 1 || i == 2) ? 1 : fibonacciRecursive(i - 1) + fibonacciRecursive(i - 2);
}

long long fibonacciIterative (int j)
{
    long long array[2];
    array[0] = 1;
    array[1] = 1;
    long long result = 0;
    for (int k = 3; k <= j; k++)
    {
        result = array[0] + array[1];
        array[0] = array[1];
        array[1] = result;
    }
    return array[1];
}

main()
{
    printf("Enter N\n");
    int n = 0;
    scanf("%d", &n);
    printf("Enter '1' for recursive, '2' for iterative.\n");
    int a = 0;
    scanf("%d", &a);
    while (n <= 0)
    {
        printf("Enter '1' for recursive, '2' for iterative.\n");
        scanf("%d", &a);
    }
    long long number = 0;
    if (a == 1)
    {
        number = fibonacciRecursive(n);
        printf("%lld\n", number);
    }
    else if (a == 2)
    {
        number = fibonacciIterative(n);
        printf("%lld\n", number);
    }
    else
        printf("Error! Need 1 or 2.\n");
}
