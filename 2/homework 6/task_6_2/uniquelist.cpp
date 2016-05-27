#include "uniquelist.h"

void UniqueList::add(int x) throw (AlreadyExistingElementExeption)
{
    if (this->exists(x))
        throw AlreadyExistingElementExeption();
    this->LinkedList::add(x);
}
