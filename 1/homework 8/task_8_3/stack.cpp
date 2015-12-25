#include "stack.h"
#include <cstddef>

struct StackNode{
    int value;
    StackNode *next;
};
struct Stack{
    StackNode *top;
};

Stack* createStack()
{
    Stack* s = new Stack;
    s->top = NULL;
    return s;
}

int showTop(Stack *s)
{
    return s->top->value;
}

void push(Stack* s, int x)
{
    StackNode* newNode = new StackNode;
    newNode->value = x;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (s->top == NULL)
        return 666;
    StackNode* temporaryNode = s->top;
    s->top = s->top->next;
    int x = temporaryNode->value;
    delete temporaryNode;
    return x;
}

void deleteStack(Stack* s)
{
    while (s->top != NULL)
    {
        StackNode* temporaryNode = s->top;
        s->top = s->top->next;
        delete temporaryNode;
    }
    delete s;
}

bool emptyStack(Stack* s)
{
    return (s->top == NULL);
}
