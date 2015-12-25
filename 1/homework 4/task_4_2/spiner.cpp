/*!
 * Выводит элементы двумерного массива N x N по спирали (по часовой стрелке, N - нечётное).
 */
#include <cstdio>
#include "spiner.h"

void spin (int **array, int lengthOfArray)
{
    int center = lengthOfArray / 2;
    printf("[%d][%d]: %d, ", center, center, array[center][center]);
    int step1 = 1;
    int step2 = 2;
    int currentRow = center;
    int currentColumn = center;
    while (step2 < lengthOfArray)
    {
        for (int i = 0; i < step1; i++)
        {
            currentColumn++;
            printf("[%d][%d]: %d, ", currentRow, currentColumn, array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step1; i++)
        {
            currentRow++;
            printf("[%d][%d]: %d, ", currentRow, currentColumn, array[currentRow][currentColumn]);
        }
        step1 += 2;
        for (int i = 0; i < step2; i++)
        {
            currentColumn--;
            printf("[%d][%d]: %d, ", currentRow, currentColumn, array[currentRow][currentColumn]);
        }
        for (int i = 0; i < step2; i++)
        {
            currentRow--;
            printf("[%d][%d]: %d, ", currentRow, currentColumn, array[currentRow][currentColumn]);
        }
        step2 += 2;
    }
    step1--;
    for (int i = 0; i < step1; i++)
    {
        currentColumn++;
        printf("[%d][%d]: %d, ", currentRow, currentColumn, array[currentRow][currentColumn]);
    }
    printf("%c%c. \n", 8, 8);
}
