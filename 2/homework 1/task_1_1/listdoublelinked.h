#pragma once
#include "list.h"

/*!
 * \brief Двусвязный список
 * Наследуется от класса List, чтобы к элементам можно было обращаться, как к просто списку (к List).
 */
class ListDoubleLinked : public List
{
public:
    ListDoubleLinked();
    ~ListDoubleLinked();
    void add(int x);
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
