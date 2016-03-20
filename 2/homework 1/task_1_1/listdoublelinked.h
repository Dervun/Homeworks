#pragma once
#include "list.h"

/*!
 * \brief Двусвязный список
 * Наследуется от класса List, чтобы к элементам можно было обращаться, как к просто списку (к List).
 */
class ListDoubleLinked : public List
{
public:
    /*!
     * \brief Создание односвязного списка
     */
    ListDoubleLinked();
    /*!
     * \brief Деструктор
     * Удаляет все ячейки, которые были в списке.
     */
    ~ListDoubleLinked();
    /*!
     * \brief Добавление
     * \param x Значение, которое надо добавить
     * Функция добавляет ячейку с заданным значением в голову списка.
     */
    void add(int x);
    /*!
     * \brief Удаление
     * \param x Значение, ячейку с которым надо удалить
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена
     * Из-за того, что в списке могут храниться несколько ячеек с одним и тем же значением, возникает неоднозначность удаления.
     * Я удаляю ячейку, ближайшую к голове списка
     */
    bool remove(int x);
    /*!
     * \brief Длина списка
     * \return Целое число - длину списка, не считая охранника.
     */
    int length()
    {
        return index;
    }
private:
    class ListNode
    {
    public:
        ListNode* next = nullptr;
        ListNode* previous = nullptr;
        int value = 0;
    };
    ListNode* first;
};
