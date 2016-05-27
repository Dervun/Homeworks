#pragma once
#include "hashfunction.h"

/*!
 * \brief H37 хэш-функция
 * Подробности работы и эффективности хэш-функции по адресу:
 * habrahabr.ru/post/219139/
 */
class HashH37 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
