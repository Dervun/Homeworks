/*!
 * E->TE'
 * E'->+TE'|-TE'|e
 * T->FT'
 * T'->*FT'|/FT'|e
 * F->id
 */
#include "lexicalAnalyser.h"
#include "parser.h"

bool E1(FILE* stream);
bool T(FILE* stream);
bool T1(FILE* stream);
bool F(FILE* stream);

bool E(FILE* stream)
{
    if (T(stream))
        return E1(stream);
    return false;
}

bool E1(FILE* stream)
{
    char symbol = 0;
    fscanf(stream, "%c", &symbol);
    if (symbol == '-' || symbol == '+')
    {
        char space = 0;
        fscanf(stream, "%c", &space);
        if (space == ' ' && T(stream))
            return E1(stream);
        else
            return false;
    }
    else
        ungetc(symbol, stream);
    return (symbol == '\n' || symbol == '\0' || symbol == ' ' ||  feof(stream));
}

bool T(FILE* stream)
{
    bool f = F(stream);
    return f ? T1(stream) : false;
}

bool T1(FILE* stream)
{
    char symbol = 0;
    fscanf(stream, "%c", &symbol);
    if (symbol == '/' || symbol == '*')
    {
        char space = 0;
        fscanf(stream, "%c", &space);
        if (space == ' ' && F(stream))
            return T1(stream);
        else
            return false;
    }
    else
        ungetc(symbol, stream);
    return true;
}

bool F(FILE* stream)
{
    return isDouble(stream);
}
