#include <cstdio>
#include <climits>

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
            if (graph[i][j] == 0)
                graph[i][j] = INT_MAX;
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
    for (int i = 0; i < graphSize; i++)
        used[i] = false;
    int* previousNode = new int[graphSize];
    for (int i = 0; i < graphSize; i++)
        previousNode[i] = INT_MAX;
    int* minWeight = new int[graphSize];
    minWeight[0] = 0;
    for (int i = 1; i < graphSize; i++)
        minWeight[i] = INT_MAX;
    printf("Minimum spanning tree:\n");
    for (int i = 0; i < graphSize; i++)
    {
        int currentNode = -1;
        for (int j = 0; j < graphSize; j++)
        {
            if (!used[j] && (currentNode == -1 || minWeight[j] < minWeight[currentNode]))
                currentNode = j;
        }
        used[currentNode] = true;
        if (previousNode[currentNode] != INT_MAX)
            printf("%d - %d (length = %d); ", previousNode[currentNode] + 1, currentNode + 1, minWeight[currentNode]);
        for (int j = 0; j < graphSize; j++)
        {
            if (graph[currentNode][j] < minWeight[j])
            {
                minWeight[j] = graph[currentNode][j];
                previousNode[j] = currentNode;
            }
        }
    }
    delete []used;
    delete []previousNode;
    delete []minWeight;
    for (int i = 0; i < maxSize; i++)
        delete []graph[i];
    delete []graph;
    return 0;
}
