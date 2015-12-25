#include <cstdio>
#include <climits>
#include <string.h>
#include <cmath>

/*!
 * Принимает строку, генерирует целое значение по нескольки (length) её символам, начиная с k-го
 * \brief hash-функция
 * \param word Строка (в данном случае - слово)
 * \param module Предел значений функции
 * \return Псевдорандомное число от 0 до ULLONG_MAX (+18,446,744,073,709,551,615)
 */
unsigned long long hashFunction(char* string, int length, int k)
{
    unsigned long long result = 0;
    for (int i = 1; i <= length && i <= 40; i++)
    {
        unsigned long long add = ((int) string[k]) * pow(2, i);
        result += add;
        k++;
    }
    return result;
}

void check(const char* string, const char* substring, const int i, const int lengthSubstring)
{
    bool equivalent = true;
    int k = i;
    for (int j = 0; j < lengthSubstring; j++)
    {
        if (string[k] != substring[j])
        {
            equivalent = false;
            break;
        }
        k++;
    }
    if (equivalent)
        printf("Substring in begining at %d symbol :)\n", i);
}

void recountHash(char* string, int i, unsigned long long &currentHash, int lengthSubstring)
{
    if (lengthSubstring < 40)
        currentHash = (currentHash - 2 * string[i - 1]) / 2 + string[i + lengthSubstring - 1] * pow(2, lengthSubstring);
    else
        currentHash = (currentHash - 2 * string[i - 1]) / 2 + string[i + 39] * pow(2, 40);
}

void searchSubstring(char* string, char* substring)
{
    int lengthString = strlen(string);
    int lengthSubstring = strlen(substring);
    int lastSymbolForCheking = lengthString - lengthSubstring;
    unsigned long long hashOfSubstring = hashFunction(substring, lengthSubstring, 0);
    unsigned long long currentHash = hashFunction(string, lengthSubstring, 0);
    if (currentHash == hashOfSubstring)
        check(string, substring, 0, lengthSubstring);
    for (int i = 1; i <= lastSymbolForCheking; i++)
    {
        recountHash(string, i, currentHash, lengthSubstring);
        if (currentHash == hashOfSubstring)
            check(string, substring, i, lengthSubstring);
    }
}

int main()
{
    char* string = new char[1000];
    char* substring = new char[1000];
    printf("Enter string: ");
    gets(string);
    printf("Enter substring: ");
    gets(substring);
    searchSubstring(string, substring);
    delete []string;
    delete []substring;
    return 0;
}
