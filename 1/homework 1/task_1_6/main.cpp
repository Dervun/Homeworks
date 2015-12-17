/*!
 * > Заданы две строки: s и s1. Найти количество вхождений s1 в s как подстроки.
 */
#include <cstdio>
#include <string.h>

main()
{
    const int maxStringSize = 1000;
    char s[maxStringSize];
    printf("Enter the string 's':\n");
    gets(s);
    char s1[maxStringSize];
    printf("Enter the string 's1':\n");
    gets(s1);
    int result = 0;
    int length = strlen(s1);
    bool haveCoincidence = false;
    for (unsigned int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s1[0])
        {
            for (int j = 0; j < length; ++j)
            {
                if (s[i + j] == s1[j])
                    haveCoincidence = true;
                else
                {
                    haveCoincidence = false;
                    break;
                }
            }
            if (haveCoincidence == true)
                result++;
        }
    }
    printf("%d\n", result);
}
