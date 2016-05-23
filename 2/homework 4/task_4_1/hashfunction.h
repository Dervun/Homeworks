#pragma once
#include <QString>

class HashFunction
{
public:
    virtual int hash(const QString &string, int module) = 0;
    virtual ~HashFunction(){}
};
