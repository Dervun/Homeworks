#include <algorithm>
#include "qsort.h"
using namespace std;

void qsort(int* a, int primordialLeft, int primordialRight)
{
    int left = primordialLeft;
    int right = primordialRight;
    int median = a[(left + right) / 2];
    while (left < right)
    {
        while ((a[left] < median) && (left <= right))
            left++;
        while ((a[right] > median) && (right >= left))
            right--;
        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    if (right > primordialLeft)
        qsort(a, primordialLeft, right);
    if (left < primordialRight)
        qsort(a, left, primordialRight);
}
