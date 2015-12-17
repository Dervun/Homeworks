/*!
 * > Реализовать возведение в целую степень (с логарифмической сложностью алгоритма).
 */
#include <cstdio>
main()
{
    unsigned long long a = 0;
    int n = 0;
    printf("Enter a^n:\n");
    scanf("%llu^%d", &a, &n);
    unsigned long long result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            result *= a;
        a *= a;
        n /= 2;
    }
    printf("Result: %llu\n", result);
}
