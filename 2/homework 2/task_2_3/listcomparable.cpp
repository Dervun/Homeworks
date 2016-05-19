#include "listcomparable.h"

int ListComparable::compareLists(ListComparable *list1, ListComparable *list2)
{
    if (list1->length() < list2->length())
        return -1;
    if (list1->length() == list2->length())
        return 0;
    return 1;
}
