#pragma once
#include <cstdio>

/*!
 * \brief Интерфейс для работы с яячейкой дерева
 * Виртуальный класс.
 */
class TreeNode
{
public:
    /*!
     * \brief Печать
     * Печать выражения, образуемного данным узлом и его потомками.
     */
    virtual void print() = 0;
    /*!
     * \brief Счёт выражения
     * Счёт выражения, образуемного данным узлом и его потомками.
     */
    virtual int calculate() = 0;
    virtual ~TreeNode(){}
protected:
    FILE *outputStream = nullptr; ///< Указатель на файл, куда писать дерево разбора выражения.
    TreeNode* leftChild = nullptr; ///< Указатель на левого потомка.
    TreeNode* rightChild = nullptr; ///< Указатель на правого потомка.
};
