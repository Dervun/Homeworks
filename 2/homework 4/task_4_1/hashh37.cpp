#include "hashh37.h"

int HashH37::hash(const QString &string, int module)
{
    int length = string.length();
    unsigned long long result = 0;
    for (int i = 0; i < length; i++)
        result = result * 37 + (int) string[i].toLatin1();
    return result % module;
}
