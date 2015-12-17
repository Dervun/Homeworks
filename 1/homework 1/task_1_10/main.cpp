/*!
 * > Реализовать программу, проверяющую, является ли строка палиндромом.
 */
#include <stdio.h>
#include <string.h>
#include <cctype>

int main()
{
    const int maxStringSize = 1000;
    char string[maxStringSize];
    printf("Enter the string:\n");
    fgets(string, maxStringSize, stdin);
    for (int k = 0; k <= strlen(string); k++)
        string[k] = tolower(string[k]);
    int left = 0;
    int right = strlen(string);
    bool coincidence = true;
    while ((left < right) && coincidence)
    {
        while (!isalpha(string[left]))
            left++;
        while (!isalpha(string[right]))
            right--;
        if (string[left] != string[right])
            coincidence = false;
        left++;
        right--;
    }
    if (coincidence)
        printf("String is palindrome\n");
    else
        printf("String is not palindrome\n");
    return 0;
}
