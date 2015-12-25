#include "charStack.h"
#include <cstddef>

struct CharStackNode{
    char value;
    CharStackNode *next;
};

struct CharStack{
    CharStackNode *top;
};

CharStack createCharStack()
{
    CharStack s;
    s.top = NULL;
    return s;
}

char showCharTop(CharStack s)
{
    return s.top->value;
}

void pushChar(CharStack &s, char x)
{
    CharStackNode *newNode = new CharStackNode;
    newNode->value = x;
    newNode->next = s.top;
    s.top = newNode;
}

char popChar(CharStack &s)
{
    CharStackNode *temporaryNode = s.top;
    s.top = s.top->next;
    char x = temporaryNode->value;
    delete temporaryNode;
    return x;
}

void deleteCharStack(CharStack &s)
{
    do
    {
        CharStackNode *temporaryNode = s.top;
        s.top = s.top->next;
        delete temporaryNode;
    }
    while (s.top != NULL);
}

bool emptyCharStack(CharStack s)
{
    return (s.top == NULL);
}
