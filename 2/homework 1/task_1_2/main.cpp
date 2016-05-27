#include <cstdio>
#include "calculatortest.h"
#include "stacktest.h"

int main()
{
    CalculatorTest test;
    QTest::qExec(&test);
    StackTest test1(true);
    QTest::qExec(&test1);
    StackTest test2(false);
    QTest::qExec(&test2);
  /* При необходимости раскомментировать.
    printf("Hi, %%username%% :)\nEnter a mathematical expression (through the gap):\n");
    char expression[1000];
    gets(expression);
    double result = Calculator::calculate(expression);
    printf("Result: %g\n", result);
    return 0;
  */
}

