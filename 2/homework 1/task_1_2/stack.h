#pragma once
template <typename T>

class Stack
{
public:
    Stack(){}
    virtual ~Stack(){}
    virtual bool push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
};
