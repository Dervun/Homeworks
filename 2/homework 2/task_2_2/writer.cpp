#include "writer.h"

void Writer::write(int **array, int size)
{
    int center = size / 2;
    print(array[center][center]);
    int step1 = 1;
    int step2 = 2;
    int currentRow = center;
    int currentColumn = center;
    while (step2 < size)
    {
        for (int i = 0; i < step1; i++)
        {
            currentColumn++;
            print(array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step1; i++)
        {
            currentRow++;
            print(array[currentRow][currentColumn]);
        }
        step1 += 2;
        for (int i = 0; i < step2; i++)
        {
            currentColumn--;
            print(array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step2; i++)
        {
            currentRow--;
            print(array[currentRow][currentColumn]);
        }
        step2 += 2;
    }
    step1--;
    for (int i = 0; i < step1 - 1; i++)
    {
        currentColumn++;
        print(array[currentRow][currentColumn]);
    }
    currentColumn++;
    print(array[currentRow][currentColumn]);
}
