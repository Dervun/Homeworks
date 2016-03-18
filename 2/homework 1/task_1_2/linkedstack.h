#pragma once
#include <cstdio>
#include "stack.h"
template <typename T>

class LinkedStack : public Stack<T>
{
public:
    LinkedStack(){}
    ~LinkedStack()
    {
        while (last)
        {
            StackNode* temporaryNode = last;
            last = last->next;
            delete temporaryNode;
        }
    }
    bool push(T newValue)
    {
        StackNode* newNode = new StackNode(newValue);
        newNode->next = last;
        last = newNode;
        return true;
    }
    T pop()
    {
        try
        {
            if(!last)
                throw "Error. Stack is empty.\n";
        }
        catch (const char* s)
        {
            puts(s);
        }
        T valueToReturn = last->value;
        StackNode* temporaryNode = last;
        last = last->next;
        delete temporaryNode;
        return valueToReturn;
    }
    T top()
    {
        try
        {
            if (!last)
                throw "Error. Stack is empty.\n";
        }
        catch (const char* s)
        {
            puts(s);
        }
        return last->value;
    }
    bool isEmpty()
    {
        return !last;
    }
    class StackNode
    {
    public:
        StackNode(T newValue)
        {
            value = newValue;
        }
        ~StackNode(){}
        T value;
        StackNode* next = nullptr;
    };
private:
    StackNode* last = nullptr;
};
