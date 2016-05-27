#include "sortedsettest.h"

LinkedList *SortedSetTest::createListWithSpecificLength(int length)
{
    LinkedList* newList = new LinkedList;
    for (int i = 0; i < length; i++)
        newList->add(50 - i);
    return newList;
}
