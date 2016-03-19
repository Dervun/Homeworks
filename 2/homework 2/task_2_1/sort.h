#pragma once
template <typename T>

class Sort
{
public:
    virtual void sort(T* array, int size) = 0;
    virtual ~Sort(){}
};
