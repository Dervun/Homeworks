#pragma once
#include "treenode.h"

/*!
 * \brief Операнд
 * Ячейка, в которой лежит операнд (целое число).
 * \warning Начинает считывать строку, как только объект создан.
 */
class Operand : public TreeNode
{
public:
    /*!
     * \brief Конструктор
     * \param outputFile Указатель на файл, в который ведётся печать.
     * \param inputString Входная строка.
     * \param i Указатель на текущий символ в строке.
     * Считывает целое число.
     */
    Operand(FILE *outputFile, char *inputString, int &i);
    /*!
     * \brief Печать
     * Печатает в файл значение (сам операнд).
     * \param outputStream Указатель на файл, в который ведётся печать.
     */
    void print()
    {
        fprintf(outputStream, "%d", value);
    }
    /*!
     * \brief Счёт
     * \return Значение, хранящееся в ячейке (значение выражения - сам операнд).
     */
    int calculate()
    {
        return value;
    }
private:
    int value = 0; ///< Собственно, сам операнд.
};

