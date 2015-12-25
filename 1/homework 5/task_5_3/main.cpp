/*!
 * > Вывести на консоль все однострочные комментарии С++ (вида // комментарий) из входного файла (вместе с символами "//").
 * > До комментария в строке может быть значимый текст, его выводить не надо, строки без комментариев не выводить.
 * > Конец строки представляется символом '\n', могут быть полезны функции fgetc и feof.
 * > Программа должна учитывать случаи, когда последовательность "//" находится внутри текстовой строки или многострочного комментария.
 * > В таких случаях ничего выводить не нужно.
 */
#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

main()
{
    FILE *ptrFile = fopen("text.txt", "rt");                 //Открытие текстового файла для чтения
    if (ptrFile == NULL)
    {
        perror("Ошибка открытия файла");
        return 0;
    }
    int multiline = 0;
    bool isText = false;
    while (!feof(ptrFile))                             // пока не конец файла
    {
        char buffer[100000];
        fgets(buffer, 100000, ptrFile);                                    // прочитать строку из файла
        int length = strlen(buffer);
        int i = 0;
        bool haveComment = false;
        for (i = 0; i < length - 1; i++)
        {
            if (buffer[i] == '/' && buffer[i + 1] == '*')
            {
                multiline++;
                break;
            }
            else if (buffer[i] == '"')
            {
                isText = !isText;
            }
            else if (buffer[i] == '*' && buffer[i + 1] == '/')
            {
                multiline--;
            }
            if (!isText && buffer[i] == '/' && buffer[i + 1] == '/')
            {
                haveComment = true;
                break;
            }
        }
        if (haveComment && !multiline && !isText)
        {
            for ( ; i < length; i++)
            {
                printf("%c", buffer[i]);
            }
            printf("\n");
        }
    }
    fclose (ptrFile);                                    // закрыть файл
}
