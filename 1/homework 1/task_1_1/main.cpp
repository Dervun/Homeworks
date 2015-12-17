/*!
 * Написать программу, считающую значение формулы x^4 + x^3 + x^2 + x + 1 за два умножения.
 */
#include <stdio.h>
main()
{
    int x = 0;
    printf("Enter X\n");
    scanf("%d", &x);
    int x2 = x * x;
    int result = (x2 + x) * (x2 + 1) + 1;
    printf("%d^4 + %d^3 + %d^2 + %d + 1 = %d\n", x, x, x, x, result);
}
