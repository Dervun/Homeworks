#pragma once
#include <QString>

/*!
 * \brief Хеш-функция
 * Интерфейс для работы с хэш-функциями.
 */
class HashFunction
{
public:
    /*!
     * \brief Подсчёт хэша по строке string, по модулю <= module.
     * \param string Входная строка, по которой считают хэш.
     * \param module Ограничение на значение хэш-функции.
     * \return Хеш, посчитанный по строке, по модулю module.
     */
    virtual int hash(const QString &string, int module) = 0;
    virtual ~HashFunction(){}
};
