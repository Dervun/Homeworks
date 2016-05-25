#include "calculator.h"

Calculator::Calculator(FILE *inputFile, FILE *outputFile)
{
    inputString = new char[1000];
    fgets(inputString, 1000, inputFile);
    int i = 0;
    root = new Operator(outputFile, inputString, i);
}

Calculator::~Calculator()
{
    delete root;
    delete inputString;
}

void Calculator::print()
{
    root->print();
}

int Calculator::calculate()
{
    return root->calculate();
}

