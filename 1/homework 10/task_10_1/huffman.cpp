#include "huffman.h"
#include "tree.h"
#include "qsort.h"
#include <algorithm>
#include <climits>
using namespace std;

/*!
 * Здесь уместна пузырьковая сортировка, потому что мне надо всего лишь передвинуть первый элемент в конец и второй на своё место.
 * Это 2 * sizeOfArray операций максимум.
 * \brief bubbleSort
 * \param array
 * \param sizeOfArray
 */
void bubbleSort(Data* array, int sizeOfArray)
{
    for (int i = sizeOfArray - 1; i >= 0; i--)
    {
        bool isClear = true;
        for (int j = 0; j < i; j++)
        {
            if (array[j].quantity > array[j + 1].quantity)
            {
                swap(array[j], array[j + 1]);
                isClear = false;
            }
        }
        if (isClear)
            return;
    }
}

void archive(FILE *stream, char* name)
{
    const int size = 128;
    int quantityOfSymbol[size];
    for (int i = 0; i < size; i++)
        quantityOfSymbol[i] = 0;
    while (!feof(stream))
    {
        char currentSymbol = '\0';
        fscanf(stream, "%c", &currentSymbol);
        quantityOfSymbol[(int) currentSymbol]++;
    }
    fclose(stream);
    printf("Quantity of symbols in the text:\n");
    for (int i = 0; i < size; i++)
    {
        if (quantityOfSymbol[i] != 0)
            printf("(%d)%c - %d\n", i, (char) i, quantityOfSymbol[i]);
    }
    printf("\n");
    int sizeOfArray = 0;
    for (int i = 0; i < size; i++)
        if (quantityOfSymbol[i] != 0)
            sizeOfArray++;
    Data* arrayOfQuantities = new Data[sizeOfArray];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (quantityOfSymbol[i] != 0)
        {
            arrayOfQuantities[k].quantity = quantityOfSymbol[i];
            Tree* newTree = createGivenTree((char) i);
            arrayOfQuantities[k].tree = newTree;
            k++;
        }
    }
    qsort(arrayOfQuantities, 0, sizeOfArray - 1);
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        arrayOfQuantities[1].tree = mergeTrees(arrayOfQuantities[0].tree, arrayOfQuantities[1].tree);
        arrayOfQuantities[1].quantity += arrayOfQuantities[0].quantity;
        arrayOfQuantities[0].quantity = INT_MAX;
        arrayOfQuantities[0].tree = NULL;
        bubbleSort(arrayOfQuantities, sizeOfArray);
    }
    FILE* archived = fopen("Archived.txt", "wt");
    Tree* finalTree = arrayOfQuantities[0].tree;
    delete []arrayOfQuantities;
    fprintTree(archived, finalTree);
    fprintf(archived, "\n");
    char** code = new char*[size];
    for (int i = 0; i < size; i++)
        code[i] = new char[8];
    for (int i = 0; i < size; i++)
        code[i][0] = '\0';
    treeToCode(finalTree, code);
    clearTree(finalTree);
    printf("Coding of simbols:\n");
    for (int i = 0; i < size; i++)
    {
        if (code[i][0] != '\0')
            printf("%c - %s\n", (char) i, code[i]);
    }
    stream = fopen(name, "rt");
    char symbol;
    fscanf(stream, "%c", &symbol);
    while (!feof(stream))
    {
        if (symbol != '\0')
            fprintf(archived, "%s", code[(int) symbol]);
        fscanf(stream, "%c", &symbol);
    }
    for (int i = 0; i < size; i++)
        delete []code[i];
    delete []code;
    fclose(archived);
    printf("File 'Archived.txt' was made :)\n");
}
