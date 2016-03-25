#pragma once
#include "writer.h"

class ConsoleWriter : public Writer
{
public:
    void write(int** array, int size);
private:
    /*!
     * \brief Обычная такая печать целого числа в консоль.
     * \param value Значение для печати
     */
    void print(int value)
    {
        printf("%d, ", value);
    }
};
