/*!
 * > Посчитать целую степень числа: a^n.
 */
#include <stdio.h>
#include <cstdlib>
main()
{
    int a = 0;
    int n = 0;
    printf("Enter a^n:\n");
    scanf("%d^%d", &a, &n);
    double result = 1;
    if (n == 0)
    {
        printf("Result:\n1\n");
        exit(1);
    }
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
            result = result * a;
    }
    else
    {
        for (int j = 1; j <= abs(n); j++)
            result = result / a;
    }
    printf("Result:\n%g", result);
}
