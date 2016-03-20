#pragma once
#include "list.h"

/*!
 * \brief Односвязный список
 * Наследуется от класса List, чтобы к элементам можно было обращаться, как к просто списку (к List).
 */
class ListSingleLinked : public List
{
public:
    ListSingleLinked();
    ~ListSingleLinked();
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
        int value = 0;
    };
    ListNode* first;
};
