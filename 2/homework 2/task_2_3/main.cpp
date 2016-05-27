/*!
 * Реализовать интерфейс ListsComparator для объектов классов LinkedList, сравнивающих 2 объекта по количеству элементов, содержащихся в списке.
 * Реализовать на его основе класс SortedSet, представляющий АТД "Отсортированное множество".
 *
 * В main писать тестирующий код было бы глупо, поэтому я написал сразу тесты.
 */
#include <cstdio>

#include "sortedset.h"
#include "sortedsettest.h"

int main()
{
    SortedSetTest test;
    QTest::qExec(&test);
    return 0;
}

