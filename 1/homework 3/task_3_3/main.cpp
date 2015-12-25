/*!
 * Реализовать программу, вычисляющую значение выражения в постфиксной записи с помощью стека.
*/
#include <cstdio>
#include "doubleStack.h"
#include "calculator.h"

main()
{
    char postfixExpression[10000];
    printf("Enter postfix expression:\n");
    gets(postfixExpression);
    double result = calculate(postfixExpression);
    printf("Result: %g", result);
}
