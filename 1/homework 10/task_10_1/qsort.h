#pragma once
#include "tree.h"

/*!
 * Структура нужна для сортировки в алгоритме Хаффмана.
 * \brief Деревья и их вес
 * \param quantity Вес дерева
 * \param tree Дерево
 */
struct Data{
    int quantity;
    Tree* tree;
};

/*!
 * Быстрая сортировка деревьев по их весам для алгоритма Хаффмана.
 * \brief QuickSort
 * \param a Массив типа Data.
 * \param primordialLeft Левая граница сортируемого массива.
 * \param primordialRight Правая граница сортируемого массива.
 */
void qsort(Data *a, int primordialLeft, int primordialRight);
