#include "lexicalAnalyser.h"
#include <cctype>

enum PartOfNumber
{
    start,
    firstSign,
    secondSign,
    integerPart,
    fractionalPart,
    point,
    degree,
    order
};

bool isDouble(FILE* stream)
{
    PartOfNumber state = start;
    char symbol = '\0';
    fscanf(stream, "%c", &symbol);
    while (symbol != ' ' && symbol != '\n' && !feof(stream))
    {
        switch (state)
        {
        case start:
        {
            if (symbol == '+' || symbol == '-')
                state = firstSign;
            else if (isdigit(symbol))
                state = integerPart;
            else
                return false;
            break;
        }
        case firstSign:
        {
            if (isdigit(symbol))
                state = integerPart;
            else
                return false;
            break;
        }
        case integerPart:
        {
            if (isdigit(symbol))
                break;
            else if (symbol == '.')
                state = point;
            else if (symbol == 'E' || symbol == 'e')
                state = order;
            else
                return false;
            break;
        }
        case point:
        {
            if (isdigit(symbol))
                state = fractionalPart;
            else
                return false;
            break;
        }
        case fractionalPart:
        {
            if (isdigit(symbol))
                break;
            else if (symbol == 'E' || symbol == 'e')
                state = order;
            else
                return false;
            break;
        }
        case order:
        {
            if (symbol == '+' || symbol == '-')
                state = secondSign;
            else if (isdigit(symbol))
                state = degree;
            else
                return false;
            break;
        }
        case secondSign:
        {
            if (isdigit(symbol))
                state = degree;
            else
                return false;
            break;
        }
        case degree:
        {
            if (isdigit(symbol))
                break;
            else
                return false;
            break;
        }
        }
        fscanf(stream, "%c", &symbol);
    }
    return state == integerPart || state == fractionalPart || state == degree;
}
