/*!
 * > Реализовать алгоритмы для работы с хэш-таблицей (разрешение коллизий методом цепочек).
 * > По данному тексту (читается из файла, не ограничен по размеру) посчитать число использований каждого слова.
 * > Вывести load factor, среднюю длину цепочки, максимальную длину цепочки и значения, которые в нее попали, общее число добавленных слов, число пустых ячеек таблицы.
 * > Для работы со строками использовать модуль "Строка" из задачи 2.
*/
#include "table.h"
#include "myString.h"
#include "tree.h"
#include "qsort.h"
#include <ctime>

main()
{
    unsigned int startTime =  clock();
    FILE* stream = fopen("Harry Potter all books.txt", "rt");
    if (stream == NULL)
    {
        printf("Can't open file 'Harry Potter all books.txt' :(\n");
        exit(1);
    }
    printf("Processing of file...\n");
    char* buffer = new char[1000];
    Table* harryPotter = createTable();
    while (!feof(stream))
    {
        fscanf(stream, "%s", buffer);
        int length = strlen(buffer);
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            if (isalpha(buffer[i]))
            {
                buffer[k] = tolower(buffer[i]);
                k++;
            }
        }
        buffer[k] = '\0';
        if (k > 0)
            addToTable(harryPotter, buffer);
    }
    fclose(stream);
    delete []buffer;
    processTable(harryPotter);
    clearTable(harryPotter);
    unsigned int endTime = clock();
    printf("Program was working %g s\n", (endTime - startTime) / 1000.0);
}
