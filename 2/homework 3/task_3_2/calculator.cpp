#include "calculator.h"

double Calculator::recalculate(int firstValue, int secondValue, char operation)
{
    double result = 0;
    switch (operation)
    {
    case '+':
    {
        result = firstValue + secondValue;
        break;
    }
    case '-':
    {
        result = firstValue - secondValue;
        break;
    }
    case '*':
    {
        result = firstValue * secondValue;
        break;
    }
    case '/':
    {
        if (secondValue != 0)
            result = (double) firstValue / secondValue;
        break;
    }
    }
    return result;
}
