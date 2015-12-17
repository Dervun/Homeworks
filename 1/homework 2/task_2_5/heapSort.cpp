#include "heapSort.h"
#include <algorithm>
using namespace std;
void makeHeap(int *arr, int n);
void heapRepair(int *arr, int pos, int n);

void makeHeap(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
        heapRepair(arr, i, n);
}

void heapRepair(int* arr, int pos, int n)
{
    int childLeft = 0;
    int childRight = 0;
    while (2 * pos + 1 < n)
    {
        childLeft = 2 * pos + 1;
        childRight = childLeft + 1;
        if (childRight < n && arr[childRight] >= arr[childLeft])
            childLeft = childRight;
        if (arr[pos] < arr[childLeft])
        {
            swap(arr[pos], arr[childLeft]);
            pos = childLeft;
        }
        else
        break;
    }
}

void heapSort(int* arr, int n)
{
    makeHeap(arr, n);
    while (n > 0)
    {
        swap(arr[0], arr[n-1]);
        n--;
        heapRepair(arr, 0, n);
    }
}
