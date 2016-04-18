#pragma once
#include <cstdio>
#include "writer.h"

class FileWriter : public Writer
{
public:  
    void write(int** array, int size);
private:
    FILE* stream = fopen("Array.txt", "wt"); ///< Указатель на файл для печати, сразу же инициализирую
    /*!
     * \brief Обычная такая печать целого числа в файл.
     * \param value Значение для печати
     */
    void print(int value)
    {
        fprintf(stream, "%d, ", value);
    }
};
