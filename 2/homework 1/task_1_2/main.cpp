#include <cstdio>
#include "calculator.h"

int main()
{
    printf("Hi, %%username%% :)\nEnter a mathematical expression (through the gap):\n");
    char expression[1000];
    gets(expression);
    double result = Calculator::calculate(expression);
    printf("Result: %g\n", result);
    return 0;
}

