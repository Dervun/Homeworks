#pragma once
#include "hashfunction.h"

/*!
 * \brief Rot13 хэш-функция
 */
class HashRot13 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
