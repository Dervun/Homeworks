#pragma once
#include "stack.h"
template <typename T>

class ArrayStack : public Stack<T>
{
public:
    ArrayStack(){}
    ~ArrayStack()
    {
        delete []values;
    }
    bool push(T value);
    T pop();
    T top();
    bool isEmpty()
    {
        return index == -1;
    }
private:
    const int maxSize = 1000;
    T* values = new T[maxSize];
    int index = -1;
};

template <typename T>
bool ArrayStack<T>::push(T value)
{
    if (index > maxSize - 2)
        return false;
    index++;
    values[index] = value;
    return true;
}

template <typename T>
T ArrayStack<T>::pop()
{
    if(index < 0)
    {
        puts("Error. Stack is empty.\n");
        return 0;
    }
    index--;
    return values[index + 1];
}

template <typename T>
T ArrayStack<T>::top()
{
    if (index < 0)
    {
        puts("Error. Stack is empty.\n");
        return 0;
    }
    return values[index];
}
