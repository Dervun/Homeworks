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
    ///Этот кусок кода работает, а тесты почему-то не работают.
    ListComparable* l = new LinkedList;
    l->add(2);
    l->add(5);
    l->add(7);
    printf("length = %d\n", l->length());
    SortedSet* s = new SortedSet;
    s->addTreeNode(l);
    delete l;
    printf("height == %d\n", s->treeHeight());
    ///Хотя он в точности повторяет первый тест.
    SortedSetTest test;
    QTest::qExec(&test);
    return 0;
}

