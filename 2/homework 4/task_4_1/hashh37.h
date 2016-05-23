#pragma once
#include "hashfunction.h"

class HashH37 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
