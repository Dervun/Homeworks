/*!
 * > Написать программу, печатающую все простые числа, не превосходящие заданного числа.
 * Печатает в файл.
 */
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

main()
{
    long long n = 0;
    printf("Enter higher limit:\n");
    scanf("%lld", &n);
    bool *array = new bool[n + 1];
    for (long long i = 2; i <= n; i++)
        array[i] = true;
    long long x = sqrt(n + 1);
    for (long long i = 2; i <= x; i++)
    {
        if (array[i])
        {
            for (long long j = i * i; j <= n; j += i)
                array[j] = false;
        }
    }
    ofstream fout;
    fout.open("Prime numbers.txt");
    for (long long i = 2; i <= n; i++)
    {
        if (array[i])
            fout << i << endl;
    }
    delete []array;
}
