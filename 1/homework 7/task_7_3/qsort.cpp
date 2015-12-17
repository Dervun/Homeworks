/*!
 * cpp-шник модуля быстрой сортировки массива типа Data в лексико-графическом порядке
 */
#include "qsort.h"

/*!
 * \brief The Data struct
 * Структура для хранения в ней слова и частоты его встречаемости в тексте
 * \param word Само слово
 * \param quantity Частота встречаемости этого слова (количество использований этого слова в тексте)
 */
struct Data{
    String* word;
    int quantity;
};

void qsortWords(Data* a, int primordialLeft, int primordialRight)
{
    int left = primordialLeft;
    int right = primordialRight;
    String* median = a[(left + right) / 2].word;
    while (left < right)
    {
        while (compareString(a[left].word, median) == smaller && left <= right)
            left++;
        while (compareString(a[right].word, median) == bigger && right >= left)
            right--;
        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    if (right > primordialLeft)
        qsortWords(a, primordialLeft, right);
    if (left < primordialRight)
        qsortWords(a, left, primordialRight);
}

