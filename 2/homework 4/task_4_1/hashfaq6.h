#pragma once
#include "hashfunction.h"

/*!
 * \brief FAQ6 хэш-функция
 * Подробности работы и эффективности хэш-функции по адресу:
 * habrahabr.ru/post/219139/
 */
class HashFAQ6 : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
