#include <cstdlib>
#include <cctype>
#include <string.h>
#include "calculator.h"

void clearBuffer(char *buffer);
double getDouble(int length, char *expression, int &i);
void takeDouble(char *postfixExpression, int &k, char *expression, int &i, bool &lastIsDigit);

double Calculator::calculate(char *inputExpression)
{
    char* expression = infixToPostfix(inputExpression);
    delete inputExpression;
    LinkedStack<double> *s = new LinkedStack<double>;
    int length = strlen(expression);
    int i = 0;
    while (i < length)
    {
        char symbol = expression[i];
        if (symbol == '-' && isdigit(expression[i + 1]))
        {
            i++;
            double x = - getDouble(length, expression, i);
            s->push(x);
        }
        else if (isdigit(symbol))
        {
            double x = getDouble(length, expression, i);
            s->push(x);
        }
        symbol = expression[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            double y = s->pop();
            double x = s->pop();
            if (symbol == '+')
            {
                double result = x + y;
                s->push(result);
                i++;
            }
            else if (symbol == '-')
            {
                double result = x - y;
                s->push(result);
                i++;
            }
            else if (symbol == '*')
            {
                double result = x * y;
                s->push(result);
                i++;
            }
            else if (symbol == '/')
            {
                double result = x / y;
                s->push(result);
                i++;
            }
        }
        else
            i++;
    }
    double result = s->pop();
    delete s;
    return result;
}

char *Calculator::infixToPostfix(char *expression)
{
    LinkedStack<char> *s = new LinkedStack<char>;
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
            while (!s->isEmpty() && ((s->top() == '*' || s->top() == '/')
                   || ((s->top() == '+' || s->top() == '-')
                       && (symbol == '+' || symbol == '-'))))
            {
                postfixExpression[k] = s->pop();
                postfixExpression[k + 1] = ' ';
                k += 2;
            }
            s->push(symbol);
            i++;
        }
        else if (symbol == '(')
        {
            s->push(symbol);
            i++;
            lastIsDigit = false;
        }
        else if (symbol == ')')
        {
            while (s->top() != '(')
            {
                postfixExpression[k] = s->pop();
                postfixExpression[k + 1] = ' ';
                k += 2;
            }
            s->pop();
            i++;
            lastIsDigit = true;
        }
        else
            i++;
    }
    while (!s->isEmpty())
    {
        postfixExpression[k] = s->pop();
        postfixExpression[k + 1] = ' ';
        k += 2;
    }
    postfixExpression[k] = '\0';
    delete s;
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

void clearBuffer(char *buffer)
{
    for (int j = 0; j < 50; j++)
        buffer[j] = ' ';
}
