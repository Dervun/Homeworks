#pragma once
#include "writer.h"

class ConsoleWriter : public Writer
{
public:
    ConsoleWriter(){}
    ~ConsoleWriter(){}
    void write(int** array, int size);
};
