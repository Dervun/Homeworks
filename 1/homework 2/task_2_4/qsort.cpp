#include <algorithm>
#include "qsort.h"
using namespace std;
void qsort(float* a, int primordialLeft, int primordialRight, Fraction* arr)
{
    int left = primordialLeft;
    int right = primordialRight;
    float median = a[(left + right) / 2];
    while (left < right)
    {
        while ((a[left] < median) && (left <= right))
            left++;
        while ((a[right] > median) && (right >= left))
            right--;
        if (left <= right)
        {
            swap(a[left], a[right]);
            swap(arr[left].numerator, arr[right].numerator);
            swap(arr[left].denominator, arr[right].denominator);
            left++;
            right--;
        }
    }
    if (right > primordialLeft)
        qsort(a, primordialLeft, right, arr);
    if (left < primordialRight)
        qsort(a, left, primordialRight, arr);
}
