#include "calculator.h"
#include <string.h>
#include <cstdio>
#include <cctype>
#include <limits.h>
#include <cstdlib>

void clearBuffer(char *buffer);
double getDouble(int length, char *expression, int &i);

double calculate(char *expression)
{
    Stack s = createStack();
    int length = strlen(expression);
    int i = 0;
    while (i < length)
    {
        char symbol = expression[i];
        if (symbol == '-' && isdigit(expression[i + 1]))
        {
            i++;
            double x = - getDouble(length, expression, i);
            push(s, x);
        }
        else if (isdigit(symbol))
        {
            double x = getDouble(length, expression, i);
            push(s, x);
        }
        symbol = expression[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            if (!haveTwoStackNode(s))
            {
                printf("Error. Expression does not postfix!\n");
                return INT_MAX;
            }
            double y = pop(s);
            double x = pop(s);
            if (symbol == '+')
            {
                double result = x + y;
                push(s, result);
                i++;
            }
            else if (symbol == '-')
            {
                double result = x - y;
                push(s, result);
                i++;
            }
            else if (symbol == '*')
            {
                double result = x * y;
                push(s, result);
                i++;
            }
            else if (symbol == '/')
            {
                double result = x / y;
                push(s, result);
                i++;
            }
        }
        else
            i++;
    }
    double result = pop(s);
    return result;
}

void clearBuffer(char *buffer)
{
    for (int j = 0; j < 50; j++)
        buffer[j] = ' ';
}

double getDouble(int length, char *expression, int &i)
{
    char buffer[50];
    clearBuffer(buffer);
    for (int k = 0; (i < length) && (isdigit(expression[i]) || expression[i] == '.'); k++)
    {
        buffer[k] = expression[i];
        i++;
    }
    double x = atof(buffer);
    return x;
}
