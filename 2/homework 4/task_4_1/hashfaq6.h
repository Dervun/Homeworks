#pragma once
#include "hashfunction.h"

class HashFAQ6 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
