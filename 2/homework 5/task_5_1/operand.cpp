#include <cstdlib>
#include "operand.h"

Operand::Operand(FILE *outputFile, char *inputString, int &i)
{
    outputStream = outputFile;
    bool needReverse = false;
    if (inputString[i] == '-')
    {
        needReverse = true;
        i++;
    }
    while (inputString[i] != ' ' && inputString[i] != ')')
    {
        value = value * 10 + (inputString[i] - '0');
        i++;
    }
    if (needReverse)
        value = -value;
}

