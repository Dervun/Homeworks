/*!
 * Написать программу преобразования инфиксной формы выражения в постфиксную.
 * Известно, что каждый операнд занимает один символ.
 * В выражении могут быть знаки +, -, *, /, скобки и цифры.
 * Пример: (1 + 1) * 2 должно преобразовываться в 1 1 + 2 *.
 * Алгоритм перевода предлагается найти самостоятельно (алгоритм "сортировочной станции" Э. Дейкстры).
*/
#include <cstdio>
#include <string.h>
#include "charStack.h"
#include "postfix.h"

main()
{
    char expression[10000];
    printf("Enter the infix mathematical expression:\n");
    gets(expression);
    char *postfixExpression = infixToPostfix(expression);
    int lengthPostfix = strlen(postfixExpression);
    printf("\nPostfix:\n");
    for (int i = 0; i < lengthPostfix; i++)
    {
        printf("%c", postfixExpression[i]);
    }
    //printf("\n(lengthPostfix = %d)\n", lengthPostfix);
    delete []postfixExpression;
}
