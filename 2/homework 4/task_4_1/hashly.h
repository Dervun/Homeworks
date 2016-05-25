#pragma once
#include "hashfunction.h"

/*!
 * \brief Ly хеш-функция
 */
class HashLy : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
