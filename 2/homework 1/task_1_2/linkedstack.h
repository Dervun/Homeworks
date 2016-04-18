#pragma once
#include <cstdio>
#include "stack.h"

template <typename T>
class LinkedStack : public Stack<T>
{
public:
    LinkedStack(){}
    ~LinkedStack();
    bool push(T newValue);
    T pop();
    T top();
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

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (last)
    {
        StackNode* temporaryNode = last;
        last = last->next;
        delete temporaryNode;
    }
}

template <typename T>
bool LinkedStack<T>::push(T newValue)
{
    StackNode* newNode = new StackNode(newValue);
    newNode->next = last;
    last = newNode;
    return true;
}

template <typename T>
T LinkedStack<T>::pop()
{
    if (isEmpty())
    {
        puts("Error. Stack is empty.\n");
        return 0;
    }
    T valueToReturn = last->value;
    StackNode* temporaryNode = last;
    last = last->next;
    delete temporaryNode;
    return valueToReturn;
}

template <typename T>
T LinkedStack<T>::top()
{
    if (isEmpty())
    {
        puts("Error. Stack is empty.\n");
        return 0;
    }
    return last->value;
}
