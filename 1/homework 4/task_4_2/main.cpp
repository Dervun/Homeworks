/*!
 * > Дан массив размерностью N x N, N — нечетное число.
 * > Вывести элементы массива при обходе его по спирали, начиная с центра.
 * Хороший пример создания, вывода и удаления динамического двумерного массива.
 */
#include <cstdio>
#include <iostream>       //Пока что умею пользоваться функцией setw() только в таком способе вывода.
#include <iomanip>        //Для функции setw(5) - она выводит объекты двумерного массива (5 - кол-во символов, отведённых под 1 элемент).
#include <cstdlib>        //Для функции random()
#include <ctime>          //Для инициализации функции random()
#include "spiner.h"
using namespace std;

main()
{
    printf("Enter length of array:\n");
    int lengthOfArray = 0;
    scanf("%d", &lengthOfArray);
    lengthOfArray = lengthOfArray / 2 * 2 + 1;
    int **array = new int*[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++)
        array[i] = new int[lengthOfArray];
    srand (time(NULL));
    for (int i = 0; i < lengthOfArray; i++)
    {
        for (int j = 0; j < lengthOfArray; j++)
            array[i][j] = rand() % 200;
    }
    printf("Array:\n");
    for (int i = 0; i < lengthOfArray; i++)
    {
        for (int j = 0; j < lengthOfArray; j++)
            cout << setw(5) << array[i][j];
        printf("\n");
    }
    spin(array, lengthOfArray);
    for (int i = 0; i < lengthOfArray; i++)
        delete []array[i];
    delete []array;
}
