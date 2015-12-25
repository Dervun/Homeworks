#include "postfix.h"
#include "charStack.h"
#include <string.h>
#include <cctype>
#include <cstdio>
struct CharStackNode{
    char value;
    CharStackNode *next;
};

struct CharStack{
    CharStackNode *top;
};
void takeDouble(char *postfixExpression, int &k, char *expression, int &i, bool &lastIsDigit);

char *infixToPostfix(char *expression)
{
    CharStack s = createCharStack();
    int lengthExpression = strlen(expression);
    char *postfixExpression = new char[10000];
    int i = 0;
    int k = 0;
    bool lastIsDigit = false;
    while (i < lengthExpression)
    {
        char symbol = expression[i];
        if (!lastIsDigit && symbol == '-')
        {
            postfixExpression[k] = expression[i];
            k++;
            i++;
            takeDouble(postfixExpression, k, expression, i, lastIsDigit);
        }
        else if (isdigit(expression[i]))
            takeDouble(postfixExpression, k, expression, i, lastIsDigit);
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            while (!emptyCharStack(s) && ((showCharTop(s) == '*' || showCharTop(s) == '/')
                   || ((showCharTop(s) == '+' || showCharTop(s) == '-')
                       && (symbol == '+' || symbol == '-'))))
            {
                postfixExpression[k] = popChar(s);
                postfixExpression[k + 1] = ' ';
                k += 2;
            }
            pushChar(s, symbol);
            i++;
        }
        else if (symbol == '(')
        {
            pushChar(s, symbol);
            i++;
            lastIsDigit = false;
        }
        else if (symbol == ')')
        {
            while (showCharTop(s) != '(')
            {
                postfixExpression[k] = popChar(s);
                postfixExpression[k + 1] = ' ';
                k += 2;
            }
            popChar(s);
            i++;
            lastIsDigit = true;
        }
        else
        {
            i++;
        }
    }
    while (!emptyCharStack(s))
    {
        postfixExpression[k] = popChar(s);
        postfixExpression[k + 1] = ' ';
        k += 2;
    }
    postfixExpression[k] = '\0';
    return postfixExpression;
}

void takeDouble(char *postfixExpression, int &k, char *expression, int &i, bool &lastIsDigit)
{
    while (isdigit(expression[i]) || expression[i] == '.')
    {
        postfixExpression[k] = expression[i];
        k++;
        i++;
    }
    postfixExpression[k] = ' ';
    k++;
    lastIsDigit = true;
}
