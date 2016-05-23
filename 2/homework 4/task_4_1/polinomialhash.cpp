#include "polinomialhash.h"
#include <cmath>

int PolinomialHash::hash(const QString &string, int module)
{
    int length = string.length();
    unsigned long long result = 0;
    for (int i = 0; i < length && i < 20; i++)
    {
        unsigned long long addition = ((int) string[i].toLatin1()) * pow(7, i + 1);
        result += addition;
    }
    int finalResult = result % module;
    finalResult = abs(finalResult);
    return finalResult;
}
