#pragma once
#include "treenode.h"

/*!
 * \brief Оператор
 * Ячейка, в которой лежит оператор (односимвольный).
 * \warning Начинает считывать строку, как только объект создан.
 */
class Operator : public TreeNode
{
public:
    /*!
     * \brief Конструктор
     * \brief outputFile Указатель на файл, в который ведётся печать.
     * \param inputString Входная строка.
     * \param i Указатель на текущий символ в строке.
     * Рекурсивно создаёт оператор и его дерево по ходу считывания строки.
     */
    Operator(FILE *outputFile, char *inputString, int &i);
    /*!
     * \brief Печать
     * Рекурсивно печатает дерево в виде <оператор> <операнд1> <операнд2>, где <операнд1> и <операнд2> сами могут быть деревьями, либо числами.
     */
    void print();
    /*!
     * \brief Счёт
     * \return Значение выражения.
     * Рекурсивно считает значение выражения, образованного текущим ущлом и его потомками.
     */
    int calculate();
    TreeNode *getNewTreeNode(char *inputString, int &i);
    ~Operator();
private:
    char value = '+'; ///< Собственно, сам оператор.
};
