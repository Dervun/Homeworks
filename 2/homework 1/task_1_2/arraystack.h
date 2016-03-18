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
    bool push(T value)
    {
        if (index > maxSize - 2)
            return false;
        index++;
        values[index] = value;
        return true;
    }
    T pop()
    {
        try
        {
            if(index < 0)
                throw "Error. Stack is empty.\n";
        }
        catch (const char* s)
        {
            puts(s);
        }
        index--;
        return values[index + 1];
    }
    T top()
    {
        try
        {
            if (index < 0)
                throw "Error. Stack is empty.\n";
        }
        catch (const char* s)
        {
            puts(s);
        }
        return values[index];
    }
    bool isEmpty()
    {
        return index == -1;
    }
private:
    const int maxSize = 1000;
    T* values = new T[maxSize];
    int index = -1;
};
