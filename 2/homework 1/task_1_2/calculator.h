#pragma once

class Calculator
{
public:
    Calculator(){}
    ~Calculator(){}
    double static calculate(char* originExpression);
private:
    void static clearBuffer(char* buffer);
    double static getDouble(int length, char* expression, int &i);
    char static *infixToPostfix(char *expression);
    void static takeDouble(char* postfixExpression, int &k, char* expression, int &i, bool &lastIsDigit);
};
