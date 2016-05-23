#include "hashrot13.h"

int HashRot13::hash(const QString &string, int module)
{
    unsigned int hash = 0;
    int length = string.length();
    for(int i = 0; i < length; i++)
    {
        hash += (unsigned char)(string[i].toLatin1());
        hash -= (hash << 13) | (hash >> 19);
    }
    return hash % module;
}
