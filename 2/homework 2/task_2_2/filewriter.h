#pragma once
#include "writer.h"

class FileWriter : public Writer
{
public:
    FileWriter(){}
    ~FileWriter(){}
    void write(int** array, int size);
};
