#pragma once

/*!
 * \brief Список
 * Это базовый класс, он не содержит реализацию, она будет в потомках.
 * Элементы списка - целые числа.
 * Есть функции добавления элемента, удаления элемента, узнавания длины списка.
 */
class List
{
public:
    List(){}
    virtual ~List(){}
    virtual void add(int x) = 0;
    virtual bool remove(int x) = 0;
    virtual int length() = 0;
protected:
    int index; ///< Текущая длина списка.
};
