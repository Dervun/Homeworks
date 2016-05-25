#include <cctype>

#include "operand.h"
#include "operator.h"

Operator::Operator(FILE *outputFile, char *inputString, int &i)
{
    outputStream = outputFile;
    i++;
    while (inputString[i] == ' ')
        i++;
    value = inputString[i];
    i++;
    leftChild = getNewTreeNode(inputString, i);
    rightChild = getNewTreeNode(inputString, i);
    i++;
}

void Operator::print()
{
    fprintf(outputStream, "(%c ", value);
    leftChild->print();
    fprintf(outputStream, " ");
    rightChild->print();
    fprintf(outputStream, ")");
}

int Operator::calculate()
{
    int result = 0;
    if (value == '+')
        result = leftChild->calculate() + rightChild->calculate();
    else if (value == '-')
        result = leftChild->calculate() - rightChild->calculate();
    else if (value == '*')
        result = leftChild->calculate() * rightChild->calculate();
    else if (value == '/')
        result = leftChild->calculate() / rightChild->calculate();
    return result;
}

TreeNode *Operator::getNewTreeNode(char *inputString, int &i)
{
    while (inputString[i] == ' ')
        i++;
    if (inputString[i] == '(')
    {
        TreeNode* result = new Operator(outputStream, inputString, i);
        return result;
    }
    if (isdigit(inputString[i]) || inputString[i] == '-')
    {
        TreeNode* result = new Operand(outputStream, inputString, i);
        return result;
    }
}

Operator::~Operator()
{
    delete leftChild;
    delete rightChild;
}

