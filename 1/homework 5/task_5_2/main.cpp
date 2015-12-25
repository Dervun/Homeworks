/*!
 * По содержимому памяти вывести значение типа double в экспоненциальной форме:
 * sm*q^(Sp), где s — знак мантиссы, m — мантисса, q — основание системы счисления,
 * S — знак порядка, p — порядок числа. Примеры допустимого вывода:
 * Enter a number: -2.5
 * Result: -1.25*2^(1)
 * Enter a number: 12312.323
 * Result: +1.5029691162109375384*2^(13)
*/
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

main()
{
    printf("Enter double x:\n");
    double x = 0;
    cin >> x;
    unsigned char *b = (unsigned char*)&x;
    int sign = (unsigned) b[7] / 128;
    printf(sign ? "-" : "+");
    int exponent = ((unsigned) b[7] % 128) * 16 + ((unsigned) b[6] / 16)  - 1023;
    double mantissa = 1;
    long long q = 2;
    for (int j = 8; j >= 1; j /= 2)
    {
        mantissa += (double) (((unsigned) b[6] / j) % 2) / q;
        q *= 2;
    }
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 128; j >= 1; j /= 2)
        {
            mantissa += (double) (((unsigned) b[i] / j) % 2) / q;
            q *= 2;
        }
    }
    printf("%.52g", mantissa);
    cout << "*2^(" << exponent << ")" << endl;
}
