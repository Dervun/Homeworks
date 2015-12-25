/*!
 * Дан файл с текстом. Вывести все слова этого текста, предварительно оставив в каждом слове
 * только первые вхождения каждой буквы.
*/
#include <cctype>
#include <string.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

void remakeAndPrintString(FILE *stream2, char *string, int begining, int ending)
{
    bool arrayOfEntry[256];
    for (int i = 0; i < 256; i++)
    {
        arrayOfEntry[i] = false;
    }
    for (int i = begining; i < ending; i++)
    {
        if (isalpha(string[i]))
        {
            int number = (int) tolower(string[i]);
            if (!arrayOfEntry[number])
            {
                arrayOfEntry[number] = true;
                fprintf(stream2, "%c", string[i]);
            }
        }
        else
            fprintf(stream2, "%c", string[i]);
    }
}

int main()
{
    FILE *stream1 = fopen("text.txt", "rt");
    if (stream1 == NULL)
    {
        printf("Can't open text.txt\n");
        exit(1);
    }
    printf("Reading of text.txt...\n");
    FILE *stream2 = fopen("resultFile.txt", "wt");
    while (!feof(stream1))
    {
        char *string = new char[10000];
        fgets(string, 10000, stream1);
        int length = strlen(string);
        int begining = 0;
        int i = 0;
        for (; i < length; i++)
        {
            if (string[i] == ' ')
            {
                remakeAndPrintString(stream2, string, begining, i + 1);
                begining = i + 1;
            }
        }
        remakeAndPrintString(stream2, string, begining, i + 1);
    }
    fclose(stream1);
    fclose(stream2);
    printf("resultFile.txt was maked.\n");
    return 0;
}
