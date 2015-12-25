/*!
 * > Объединить предыдущие две задачи в одну программу — реализовать программу-калькулятор, вычисляющую значение арифметического выражения в инфиксной нотации.
 * > Выражение вводится с консоли, должны поддерживаться операции {+, -, *, /} и скобки, операнды считать односимвольными.
 * Я сделал для чисел с плавающей точкой, а не для цифр.
*/
#include "calculator.h"
#include "charStack.h"
#include "doubleStack.h"
#include "postfix.h"
#include <cstdio>
#include <string.h>

main()
{
    char expression[10000];
    printf("Enter mathematical expression (enter'0' to exit):\n");
    gets(expression);
    while (expression[0] != '0')
    {
        char *postfixExpression = infixToPostfix(expression);
        double result = calculate(postfixExpression);
        delete []postfixExpression;
        printf("Result: %g\n", result);
        printf("Enter mathematical expression (enter'0' to exit):\n");
        gets(expression);
    }
}
