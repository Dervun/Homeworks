#pragma once
#include "hashfunction.h"

class PolinomialHash : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
