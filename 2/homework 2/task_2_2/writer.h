#pragma once

class Writer
{
public:
    Writer(){}
    virtual void write(int** array, int size) = 0;
    virtual ~Writer(){}
};
