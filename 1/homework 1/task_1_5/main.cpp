/*!
 * Работает для круглых скобок только.
 * > Написать программу проверки баланса скобок в исходной строке (т.е. число открывающих скобок равно числу закрывающих и выполняется правило вложенности скобок).
 */
#include <stdio.h>
#include <string.h>

main()
{
    const int maxStringSize = 1000;
    char string[maxStringSize];
    printf("Enter the string:\n");
    fgets(string, maxStringSize, stdin);
    int counter = 0;
    bool balanceCorrect = true;
    for (unsigned int i = 0; i < strlen(string) && balanceCorrect; i++)
    {
        if (string[i] == '(')
            counter++;
        else if (string[i] == ')')
            counter--;
        if (counter < 0)
            balanceCorrect = false;
    }
    if (balanceCorrect)
        printf("Balanced\n");
    else
        printf("Not balanced\n");
}
