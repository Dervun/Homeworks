#pragma once
#include "hashfunction.h"

/*!
 * \brief Rot13 хэш-функция
 * Подробности работы и эффективности хэш-функции по адресу:
 * habrahabr.ru/post/219139/
 */
class HashRot13 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
