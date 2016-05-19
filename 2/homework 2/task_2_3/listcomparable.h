#pragma once

/*!
 * \brief Сomparator of lists
 * Cравнивает 2 списка по количеству элементов, содержащихся в них.
 */
class ListComparable
{
public:
    ListComparable(){}
    /*!
     * \brief Compare of lists
     * \param list1 Первый список
     * \param list2 Второй список
     * \return -1, если первый список меньше второго; 0, если списки равны; 1, если первый список больше сторого.
     */
    static int compareLists(ListComparable* list1, ListComparable* list2);
    virtual void add(int x) = 0;
    virtual bool remove(int x) = 0;
    virtual int length() = 0;
    virtual ListComparable* getClone() = 0;
    virtual ~ListComparable(){}
protected:
    int listLength = 0; ///< Текущая длина списка.
};
