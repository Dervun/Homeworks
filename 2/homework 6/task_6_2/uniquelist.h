#pragma once
#include "linkedlist.h"

/*!
 * \brief Уникальный список
 * Сортированный двусвязный список, не содержащий повторяющихся значений.
 */
class UniqueList : public LinkedList
{
public:
    ~UniqueList(){}
    /*!
     * \brief Класс исключения, генерирующегося при попытке добавить в список уже существующего элемента.
     */
    class AlreadyExistingElementExeption : public std::exception
    {
    public:
        const char *details() const noexcept
        {
            return "An attempt to add an already existing element";
        }
    };
    void add(int x) throw (AlreadyExistingElementExeption);
};
