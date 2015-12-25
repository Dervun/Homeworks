/*!
 * > Даны две строки. Определить, можно ли, переставляя символы в первой строке, получить вторую строку.
 * > Хочется решение быстрее, чем за O(n^2).
 * Сделаем вид, что строки нам введут с консоли.
 * Работает за O(n)
 */
#include <cstdio>     //Сделаем вид, что строки нам введут с консоли.
#include <string.h>

main()
{
    const int maxStringSize = 10000;
    char* string1 = new char[maxStringSize];
    char* string2 = new char[maxStringSize];
    printf("Enter the first string:\n");
    gets(string1);
    printf("Enter the second string:\n");
    gets(string2);
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    if (length1 == length2)                      //Если строки не равны, то проверять что-то бессмысленно.
    {
        int lengthOfArray = 256;
        int array1[lengthOfArray];
        int array2[lengthOfArray];
        for (int i = 0; i < lengthOfArray; i++)
        {
            array1[i] = 0;
            array2[i] = 0;
        }
        for (int i = 0; i < length1; i++)
        {
            array1[(int) string1[i]]++;
            array2[(int) string2[i]]++;
        }
        bool haveEquivalence = true;
        for (int i = 0; i < lengthOfArray; i++)
        {
            if (array1[i] != array2[i])
                haveEquivalence = false;
        }
        if (haveEquivalence)
            printf("Congratulation! Second string could be constructed.");
        else
            printf("Impossible to construct the second string.");
    }
    else
        printf("Impossible to construct the second string.");
    delete []string1;
    delete []string2;
}
