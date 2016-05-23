#include "hashfaq6.h"

int HashFAQ6::hash(const QString &string, int module)
{
    unsigned int hash = 0;
    int length = string.length();
    for (int i = 0; i < length; i++)
    {
        hash += (unsigned char)(string[i].toLatin1());
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % module;
}
