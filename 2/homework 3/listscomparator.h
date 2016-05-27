#pragma once
#include "linkedlist.h"

/*!
 * \brief Сomparator of lists
 * Cравнивает 2 списка по количеству элементов, содержащихся в них.
 */
class ListsComparator
{
public:
    /*!
     * \brief Compare of lists
     * \param list1 Первый список
     * \param list2 Второй список
     * \return -1, если первый список меньше второго; 0, если списки равны; 1, если первый список больше сторого.
     */
    static int compareLists(LinkedList* list1, LinkedList* list2);
};
