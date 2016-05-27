#include "listcomparator.h"

int ListComparator::compareLists(LinkedList *list1, LinkedList *list2)
{
    if (list1->length() < list2->length())
        return -1;
    if (list1->length() == list2->length())
        return 0;
    return 1;
}
