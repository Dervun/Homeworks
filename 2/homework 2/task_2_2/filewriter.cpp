#include <cstdio>
#include "filewriter.h"

void FileWriter::write(int **array, int size)
{
    FILE* stream = fopen("Array.txt", "wt");
    int center = size / 2;
    fprintf(stream, "%d, ", array[center][center]);
    int step1 = 1;
    int step2 = 2;
    int currentRow = center;
    int currentColumn = center;
    while (step2 < size)
    {
        for (int i = 0; i < step1; i++)
        {
            currentColumn++;
            fprintf(stream, "%d, ", array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step1; i++)
        {
            currentRow++;
            fprintf(stream, "%d, ", array[currentRow][currentColumn]);
        }
        step1 += 2;
        for (int i = 0; i < step2; i++)
        {
            currentColumn--;
            fprintf(stream, "%d, ", array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step2; i++)
        {
            currentRow--;
            fprintf(stream, "%d, ", array[currentRow][currentColumn]);
        }
        step2 += 2;
    }
    step1--;
    for (int i = 0; i < step1 - 1; i++)
    {
        currentColumn++;
        fprintf(stream, "%d, ", array[currentRow][currentColumn]);
    }
    currentColumn++;
    fprintf(stream, "%d.", array[currentRow][currentColumn]);
}
