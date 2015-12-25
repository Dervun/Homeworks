#include <cstdio>
#include "stack.h"

/*!
 * \brief Проверка открытия файла
 * \param stream Указатель на открываемый файл
 * \param name Имя открываемого файла
 * \return В случае неудавшегося открытия файла печатает, что файл с именем name не удалось открыть и возвращает false, иначе true.
 */
bool checkOpen(const FILE* stream, const char* name)
{
    if (stream == NULL)
    {
        printf("Can't open file '%s' :(\n", name);
        return false;
    }
    return true;
}

int readGraph(FILE* stream, int** graph)
{
    int i = 0;
    while (!feof(stream))
    {
        char lastSymbol = '\0';
        int j = 0;
        while (lastSymbol != '\n' && !feof(stream))
        {
            fscanf(stream, "%d%c", &graph[i][j], &lastSymbol);
            j++;
        }
        i++;
    }
    return i;
}

int main()
{
    char name[] = "graph.txt";
    FILE* stream = fopen(name, "rt");
    if(!checkOpen(stream, name))
        return 1;
    const int maxSize = 100;
    int** graph = new int*[maxSize];
    for (int i = 0; i < maxSize; i++)
        graph[i] = new int[maxSize];
    int graphSize = readGraph(stream, graph);
    fclose(stream);
    bool* used = new bool[graphSize];
    for (int j = 0; j < graphSize; j++)
        used[j] = false;
    bool allWasUsed = false;
    Stack* s = createStack();
    printf("Connected components of graph:\n");
    while (!allWasUsed)
    {
        int i = 0;
        while (used[i] && i < graphSize)
            i++;
        if (i == graphSize)
        {
            allWasUsed = true;
            break;
        }
        push(s, i);
        used[i] = true;
        while (!emptyStack(s))
        {
            i = pop(s);
            printf("%d, ", i + 1);
            for (int k = 0; k < graphSize; k++)
            {
                if (graph[i][k] != 0 && !used[k])
                {
                    push(s, k);
                    used[k] = true;
                }
            }
        }
        printf("%c%c. \n", 8, 8);
    }
    deleteStack(s);
    delete []used;
    for (int i = 0; i < maxSize; i++)
        delete []graph[i];
    delete []graph;
    return 0;
}
