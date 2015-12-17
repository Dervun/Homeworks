#include "myString.h"

/// \brief Структура, описывающая строку (String)
/*!
 * Структура, состоящая из указателя на массив символов и длины этого массива
 * \param string Массив символов
 * \param length Длина строки (без нуль-терминатора)
*/
struct String{
    char *string;
    int length;
};

String* createString()
{
    String *s = new String;
    s->string = NULL;
    s->length = 0;
    return s;
}

String* createGivenString(char *buffer)
{
    String *s = createString();
    addToString(s, buffer);
    return s;
}

void addToString(String *s, char *buffer)
{
    int lengthBuffer = strlen(buffer);
    if (s->string == NULL)
    {
        char *newString = new char[lengthBuffer + 1];
        for (int i = 0; i < lengthBuffer + 1; i++)
            newString[i] = buffer[i];
        if (newString[lengthBuffer - 1] == '\n')
            newString[lengthBuffer - 1] = '\0';
        s->string = newString;
        s->length = strlen(s->string);
    }
    else
    {
        char *newString = new char[s->length + lengthBuffer + 1];
        int i = 0;
        int k = 0;
        while (i < s->length)
        {
            newString[i] = s->string[i];
            i++;
        }
        while (i < s->length + lengthBuffer + 1)
        {
            newString[i] = buffer[k];
            i++;
            k++;
        }
        if (newString[s->length + lengthBuffer - 1] == '\n')
            newString[s->length + lengthBuffer - 1] = '\0';
        char *temporaryPointer = s->string;
        s->string = newString;
        s->length = strlen(s->string);
        delete []temporaryPointer;
    }
}

void removeString(String *s)
{
    if(!emptyString(s))
        delete []s->string;
    delete []s;
}

Comparison compareString(String *s1, String *s2)
{
    int length = min(s1->length, s2->length);
    for (int i = 0; i < length; i++)
    {
        if ((int) s1->string[i] > (int) s2->string[i])
            return bigger;
        if ((int) s1->string[i] < (int) s2->string[i])
            return smaller;
    }
    if (s1->length < s2->length)
        return smaller;
    if(s1->length > s2->length)
        return bigger;
    return equivalent;
}

char* stringToChar(String *s)
{
    char *resultString = new char[s->length + 1];
    for (int i = 0; i < s->length + 1; i++)
        resultString[i] = s->string[i];
    return resultString;
}

String* clone(String* s)
{
    String* s1 = createGivenString(s->string);
    return s1;
}

char* allocateString(String *s, int begining, int end)
{
    if (begining < 0 || end > s->length)
        return NULL;
    char* allocatedString = new char[end - begining + 2];
    int k = 0;
    for (int i = begining; i <= end; i++)
    {
        allocatedString[k] = s->string[i];
        k++;
    }
    allocatedString[k] = '\0';
    return allocatedString;
}

bool emptyString(String *s)
{
    return (s->string == NULL);
}

int lengthString(String *s)
{
    return s->length;
}
