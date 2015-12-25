#include "dijkstra.h"
#include "queue.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

void clearGraph(int** graph, int quantityOfCities)
{
    for (int i = 0; i < quantityOfCities; i++)
    {
        for (int j = 0; j < quantityOfCities; j++)
            graph[i][j] = 0;
    }
}

void readGraph(FILE* stream, int** graph, int quantityOfRoads)
{
    for (int i = 0; i < quantityOfRoads; i++)
    {
        int city1;
        int city2;
        int length;
        fscanf(stream, "%d %d %d", &city1, &city2, &length);
        city1--;
        city2--;
        graph[city1][city2] = graph[city2][city1] = length;
    }
}

void printGraph(int** graph, int quantityOfCities)
{
    for (int i = 0; i < quantityOfCities; i++)
    {
        for (int j = 0; j < quantityOfCities; j++)
            cout << setw(2) << graph[i][j];
        printf("\n");
    }
}

void processQueue(Queue* q, bool* used, int** graph, int* minLengthOfWay, int* previousNode, const int quantityOfCities)
{
    while (!emptyQueue(q))
    {
        int currentNode = pop(q);
        bool haveMaxInt = false;
        for (int i = 0; i < quantityOfCities; i++)
        {
            if (graph[currentNode][i] != 0 && minLengthOfWay[i] != INT_MAX && minLengthOfWay[i] + graph[currentNode][i] < minLengthOfWay[currentNode])
            {
                minLengthOfWay[currentNode] = minLengthOfWay[i] + graph[currentNode][i];
                previousNode[currentNode] = i;
            }
            if (graph[currentNode][i] != 0 && minLengthOfWay[i] == INT_MAX)
                haveMaxInt = true;
            if (i == 0 && minLengthOfWay[currentNode] == graph[currentNode][i])
            {
                haveMaxInt = false;
                break;
            }
        }
        if (!haveMaxInt)
            used[currentNode] = true;
        for (int i = 0; i < quantityOfCities; i++)
        {
            if (graph[currentNode][i] != 0 && !used[i])
                push(q, i);
        }
    }
}

void printResult(int* minLengthOfWay, int* previousNode, int quantityOfCities)
{
    printf("n) #Number_of_city - length_of_way_from_cuptured_city_to_first_city; this_way\n");
    printf("0) #1 - 0; not way :)\n");
    for (int j = 1; j < quantityOfCities; j++)
    {
        int currentMin = INT_MAX;
        int currentMinIndex = 0;
        for (int i = 1; i < quantityOfCities; i++)
        {
            if (minLengthOfWay[i] < currentMin)
            {
                currentMin = minLengthOfWay[i];
                currentMinIndex = i;
            }
        }
        printf("%d) #%d - %d; %d", j, currentMinIndex + 1, minLengthOfWay[currentMinIndex], currentMinIndex + 1);
        int i = currentMinIndex;
        while (previousNode[i] != 0)
        {
            printf(" -> %d", previousNode[i] + 1);
            i = previousNode[i];
        }
        printf(" -> 1\n");
        minLengthOfWay[currentMinIndex] = INT_MAX;
    }
}

void dijkstra(FILE* stream)
{
    int quantityOfCities = 0;
    int quantityOfRoads = 0;
    fscanf(stream, "%d %d\n", &quantityOfCities, &quantityOfRoads);
    int** graph = new int*[quantityOfCities];
    for (int i = 0; i < quantityOfCities; i++)
        graph[i] = new int[quantityOfCities];
    clearGraph(graph, quantityOfCities);
    readGraph(stream, graph, quantityOfRoads);
    fclose(stream);
    //printGraph(graph, quantityOfCities);
    int* minLengthOfWay = new int[quantityOfCities];
    minLengthOfWay[0] = 0;
    for (int i = 1; i < quantityOfCities; i++)
        minLengthOfWay[i] = INT_MAX;
    int* previousNode = new int[quantityOfCities];
    for (int i = 0; i < quantityOfCities; i++)
        previousNode[i] = INT_MIN;
    bool* used = new bool[quantityOfCities];
    for (int i = 0; i < quantityOfCities; i++)
        used[i] = false;
    Queue* q = createQueue();
    push(q, 0);
    used[0] = true;
    processQueue(q, used, graph, minLengthOfWay, previousNode, quantityOfCities);
    delete []used;
    deleteQueue(q);
    for (int i = 0; i < quantityOfCities; i++)
        delete []graph[i];
    delete []graph;
    printResult(minLengthOfWay, previousNode, quantityOfCities);
    delete []previousNode;
    delete []minLengthOfWay;
}
