#pragma once
#include "hashfunction.h"

/*!
 * \brief FAQ6 хэш-функция
 */
class HashFAQ6 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
