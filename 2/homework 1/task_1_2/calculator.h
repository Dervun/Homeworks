#pragma once

class Calculator
{
public:
    Calculator(){}
    ~Calculator(){}
    double static calculate(const char* originExpression);
private:
    void static clearBuffer(char* buffer);
    double static getDouble(int length, const char* expression, int &i);
    char static *infixToPostfix(const char *expression);
    void static takeDouble(char* postfixExpression, int &k, const char* expression, int &i, bool &lastIsDigit);
};
