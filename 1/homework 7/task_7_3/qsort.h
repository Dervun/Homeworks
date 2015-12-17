/*!
 * Header модуля быстрой сортировки массива типа Data в лексико-графическом порядке
 */
#pragma once
#include "myString.h"

struct Data;

/*!
 * Функция для быстрой сортировки (Quick sort) списка слов в алфавитном порядке
 * \brief Сортирует список слов
 * \param a Указатель на массив слов с частотами их встречаемости
 * \param primordialLeft Указатель на крайнюю левую ячейку сортируемого массива
 * \param primordialRight Указатель на крайнюю правую ячейку сортируемого массива
 */
void qsortWords(Data* a, int primordialLeft, int primordialRight);
