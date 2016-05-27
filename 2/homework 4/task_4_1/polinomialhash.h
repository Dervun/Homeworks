#pragma once
#include "hashfunction.h"
/*!
 * \brief Полиномиальная хэш-функция
 * Подробнее:
 * habrahabr.ru/post/142589/
 */
class PolinomialHash : public HashFunction
{
public:
    int hash(const QString &string, int module);
};
