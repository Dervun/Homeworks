#pragma once
#include "hashfunction.h"

/*!
 * \brief Ly хеш-функция
 * Подробности работы и эффективности хэш-функции по адресу:
 * habrahabr.ru/post/219139/
 */
class HashLy : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
