#include "hashly.h"

int HashLy::hash(const QString &string, int module)
{
    unsigned int hash = 0;
    int length = string.length();
    for(int i = 0; i < length; i++)
    hash = (hash * 1664525) + (unsigned char)(string[i].toLatin1()) + 1013904223;
    return hash % module;
}
