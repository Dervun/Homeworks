/*!
 * > Реализовать алгоритм нахождения неполного частного от деления a на b (целые числа), используя только операции сложения, вычитания и умножения.
 */
#include <stdio.h>
#include <cstdlib>
main()
{
    int a = 0;
    int b = 0;
    printf("Enter integer a/b:\n");
    scanf("%d/%d", &a, &b);
    int result = 0;
    if (b == 0)
    {
        printf("Math error. Enter b not equal 0.");
        exit(1);
    }
    if ((a >= 0 && b > 0) || (a < 0 && b < 0))
    {
        if (abs(a) < abs(b))
            result = 0;
        else
        {
            while (abs(a) >= abs(b))
            {
                a -= b;
                result += 1;
            }
        }
    }
    else
    {
        if (abs(a) < abs(b))
            result = 0;
        else
        {
            while (abs(a) >= abs(b))
            {
                a += b;
                result += 1;
            }
            result *= (-1);
        }
    }
    printf("Result:\n %d\n", result);
}
