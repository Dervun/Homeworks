#include <cstdio>
#include "linkedstack.h"

bool LinkedStack::isEmpty()
{
    return !last;
}

LinkedStack::StackNode::StackNode(double newValue)
{
    value = newValue;
}
