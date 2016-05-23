#pragma once
#include "hashfunction.h"

class HashRot13 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
