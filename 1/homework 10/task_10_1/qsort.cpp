#include <algorithm>
#include <string.h>
#include "qsort.h"
using namespace std;
void qsort(Data *a, int primordialLeft, int primordialRight)
{
    int left = primordialLeft;
    int right = primordialRight;
    int median = a[(left + right) / 2].quantity;
    while (left < right)
    {
        while ((a[left].quantity < median) && (left <= right))
            left++;
        while ((a[right].quantity > median) && (right >= left))
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
