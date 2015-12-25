#include "doubleStack.h"
struct StackNode{
    double value;
    StackNode *next;
};

struct Stack{
    StackNode *top;
};

Stack createStack()
{
    Stack s;
    s.top = NULL;
    return s;
}

double showTop(Stack s)
{
    return s.top->value;
}

void push(Stack &s, double x)
{
    StackNode *newNode = new StackNode;
    newNode->value = x;
    newNode->next = s.top;
    s.top = newNode;
}

double pop(Stack &s)
{
    StackNode *temporaryNode = s.top;
    s.top = s.top->next;
    double x = temporaryNode->value;
    delete temporaryNode;
    return x;
}

void deleteStack(Stack &s)
{
    do
    {
        StackNode *temporaryNode = s.top;
        s.top = s.top->next;
        delete temporaryNode;
    }
    while (s.top != NULL);
}

bool haveTwoStackNode(Stack s)
{
    return (s.top != NULL && s.top->next != NULL);
}
