#pragma once
#include "hashfunction.h"

class HashLy : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
