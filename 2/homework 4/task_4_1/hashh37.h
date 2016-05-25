#pragma once
#include "hashfunction.h"

/*!
 * \brief H37 хэш-функция
 */
class HashH37 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
