#include "sortedsettest.h"

ListComparable *SortedSetTest::createListWithSpecificLength(int length)
{
    ListComparable* newList = new LinkedList;
    for (int i = 0; i < length; i++)
        newList->add(50 - i);
    return newList;
}
