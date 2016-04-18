#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "consolewriter.h"
#include "filewriter.h"

using namespace std;

/*!
 * \brief Структурка для выбора типа печати
 */
enum Select{
    console = 1, ///< Печать в консоль
    file ///< Печать в файл
};

/*!
 * \brief Создаёт двумерный массив
 * \param lengthOfArray Длина массива
 * \return Указатель на созданный массив
 * Заполняет двумервый массив заданной длины рандомно целыми числами от 0 до 99 включительно.
 */
int** buildArray(int lengthOfArray)
{
    int **array = new int*[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++)
        array[i] = new int[lengthOfArray];
    srand(time(NULL));
    const unsigned int randomLimit = 100;
    for (int i = 0; i < lengthOfArray; i++)
        for (int j = 0; j < lengthOfArray; j++)
            array[i][j] = rand() % randomLimit;
    printf("Array:\n");
    for (int i = 0; i < lengthOfArray; i++)
    {
        for (int j = 0; j < lengthOfArray; j++)
            cout << setw(5) << array[i][j];
        printf("\n");
    }
    return array;
}

/*!
 * \brief Удаляет двумерный массив
 * \param array Указатель на удаляемый массив
 * \param lengthOfArray Длина массива
 * Вынес сюда, чтобы не загромождать main.
 */
void removeArray(int** array, int lengthOfArray)
{
    for (int i = 0; i < lengthOfArray; i++)
        delete []array[i];
    delete []array;
}

int main()
{
    printf("Enter length of array:\n");
    int lengthOfArray = 0;
    scanf("%d", &lengthOfArray);
    lengthOfArray = lengthOfArray / 2 * 2 + 1;   //На всякий случай. Вдруг введут чётное число N.
    int** array = buildArray(lengthOfArray);
    printf("Write array to console or to file?\nEnter 1 or 2 respectively:\n");
    Select x = console;
    int y = 1;
    scanf("%d", &y);
    x = (Select) y;
    if (x == console)
    {
        Writer* consoler = new ConsoleWriter;
        consoler->write(array, lengthOfArray);
    }
    else
    {
        Writer* filer = new FileWriter;
        filer->write(array, lengthOfArray);
        printf("File 'Array.txt' was made :)\n");
    }
    removeArray(array, lengthOfArray);
    return 0;
}

