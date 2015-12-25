/*!
 * > Пронумеровать вершины ориентированного графа в произвольном порядке латинскими буквами.
 * > На входе имя файла с заданием графа и начальная вершина, от которой будет осуществляться нумерация.
 * > Предполагается, что в графе одна компонента связности.
 * Обход графа в ширину
 */
#include "queue.h"
#include <cstdlib>
#include <ctime>

/*!
 * \brief Проверка открытия файла
 * \param stream Указатель на открываемый файл
 * \param name Имя открываемого файла
 * В случае неудавшегося открытия файла печатает, что файл с именем name не удалось открыть и завершает программу.
 */
void checkOpen(const FILE* stream, const char* name)
{
    if (stream == NULL)
    {
        printf("Can't open file '%s' :(\n", name);
        exit(1);
    }
}

int main()
{
    char name[] = "graph.txt";
    FILE* stream = fopen(name, "rt");
    checkOpen(stream, name);
    int graph[100][100];
    int row = 1;
    int column = 1;
    while (!feof(stream) && row < 100)
    {
        column = 1;
        char currentSymbol = '\0';
        while (!feof(stream) && currentSymbol != '\n')
        {
            fscanf(stream, "%d%c", &graph[row][column], &currentSymbol);
            column++;
        }
        row++;
    }
    fclose(stream);
    int graphSize = row;
    int startNode = 0;
    char* numerationOfGraph = new char[graphSize];
    for (int i = 0; i < graphSize; i++)
        numerationOfGraph[i] = 'X';
    printf("Enter start node:\n");
    scanf("%d", &startNode);
    Queue* q = createQueue();
    push(q, startNode);
    bool* used = new bool[graphSize];
    for (int i = 0; i < graphSize; i++)
        used[i] = false;
    used[startNode] = true;
    int k = 0;
    while (!emptyQueue(q))
    {
        int currentNumber = pop(q);
        numerationOfGraph[currentNumber] = 'a' + k;
        k++;
        for (int i = 1; i < graphSize; i++)
        {
            if (graph[currentNumber][i] != 0 && !used[i])
            {
                push(q, i);
                used[i] = true;
            }
        }
    }
    delete []used;
    deleteQueue(q);
    printf("Numeration of graph:\n");
    for (int i = 1; i < graphSize; i++)
        printf("%d - %c\n", i, numerationOfGraph[i]);
    delete []numerationOfGraph;
    return 0;
}
