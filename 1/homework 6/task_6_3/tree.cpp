#include "tree.h"
#include <cstddef>
#include <cstdio>
#include <algorithm>
using namespace std;

/*!
 * \brief Узел дерева
 * \param value Значение, хранящееся в узле
 * \param height Высота поддерева, образовонного данным узлом и его потомками
 * \param leftChild Левый потомок
 * \param rightChild Правый потомок
 */
struct TreeNode
{
   int value;
   int height;
   TreeNode *leftChild;
   TreeNode *rightChild;
};
/*!
 * Интовое АВЛ-дерево (балансирующееся, у которого разница любых 2-х поддеревьев, корни которых являются потомками одного узла, не больше 1).
 * \brief Дерево
 * \param root Корень дерева
 */
struct Tree
{
    TreeNode *root;
};
/*!
 * Функция добавляет в дерево лист. Предполагается, что указатель на добавляемый лист верный.
 * \brief Добавляет лист
 * \param currentNode Указатель на добавляемый лист
 * \param x Значение, которое будет храниться в листе
 */
void addTreeLeaf(TreeNode* &currentNode, int x);
/*!
 * Предполагается, что такого значения в дереве ещё нет.
 * \brief Добавляет новую ячейку в дерево туда, куда нужно
 * \param currentNode Текущая ячейка, от которой идёт добавление
 * \param x Значение для добавления в новую ячейку
 */
void addTreeNode(TreeNode *&currentNode, int x);
/*!
 * Если ячейки не существует, возвращает NULL;
 * если значение совпало, возвращает адрес указателя на искомую ячейку;
 * если значение меньше искомого, запускает себя от левого потомка;
 * если значение больше искомого, запускает себя от правого потомка.
 * \brief Ищет ячейку с заданным значением
 * \param currentNode Текущая ячейка, от которой ведётся поиск.
 * \param x Искомое значение.
 * \return Указатель на указатель на искомую ячейку или NULL, если ячейка не нашлась.
 */
TreeNode **search(TreeNode *&currentNode, int x);
/*!
 * Предполагается, что функция запускается в том случае, когда удаляемый элемент существует.
 * Если значение больше искомого, запускает себя от правого потомка;
 * если значение меньше искомого, запускает себя от левого потомка.
 * \brief Рекурсивно удаляет ячейку
 * \param currentNode Текущий узел
 * \param x Искомое значение.
 */
void removeTreeNode(TreeNode *&currentNode, int x);
/*!
 * Находит узел с минимальным значением, по ходу дела сохраняет путь до этого минимального значения в массив array
 * \brief Находит узел с минимальным значением
 * \param currentNode Текущий узел
 * \return Указатель на указатель на искомую ячейку.
 */
TreeNode **findMin(TreeNode *&currentNode);
/*!
 * Рекурсивная функция. Запускает себя от левого поддерева, от правого поддерева,
 * чистит память, выделенную под текущий узел.
 * \brief Удаляет дерево
 * \param currentNode Текущий узел
 */
void clearTree(TreeNode *currentNode);
/*!
 * Присваивает данному узлу высоту - максимальную из высот поддеревьев + 1.
 * \brief Обновляет высоту
 * \param currentNode Данный узел
 */
void updateHeight(TreeNode *currentNode);
/*!
 * См. Википедию
 * \brief Малое левое вращение
 * \param rootNode Узел, от которого идёт вращение.
 */
void smallLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Малое правое вращение
 * \param rootNode Узел, от которого идёт вращение.
 */
void smallRightRotate(TreeNode *&rootNode);
/*!
 * \brief Большое левое вращение
 * \param rootNode Узел, от которого идёт вращение.
 */
void bigLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Большое правое вращение
 * \param rootNode Узел, от которого идёт вращение.
 */
void bigRightRotate(TreeNode *&rootNode);
/*!
 * \brief Равновесие.
 * \param rootNode Узел, у которого проверяется равновесие.
 * \return Разницу между высотой правого и высотой левого поддеревьев
 */
int equilibrium(TreeNode *rootNode);
/*!
 * Если требуется (если модуль равновесия >= 2), происходит балансировка данного поддерева.
 * В зависимости от требований (См. Википедию) производится одно из вращеий.
 * \brief Балансировка
 * \param rootNode Корень поддерева
 */
void balance(TreeNode *&rootNode);
/*!
 * Печатает в консоль значение в текущем узле, запускает себя от левого и правого потомков.
 * \brief Рекурсивная ф-я печати
 * \param currentNode указатель на текущий узел
 */
void printTree(TreeNode *currentNode);
/*!
 * Она же - печать от меньшего к большему. Рекурсивная функция запускает себя от левого потомка, печатает значение в узле, запускает себя от правого потомка.
 * \brief Печать дерева и инфиксной форме.
 * \param currentNode Текущий узел, от которого ведётся печать.
 */
void printInfix(TreeNode *currentNode);
/*!
 * Рекурсивная функция, запускает себя от правого потомка, печатает значение в узле, запускает себя от левого потомка.
 * \brief Печать дерева от большего к меньшему
 * \param currentNode Текущий узел, от которого ведётся печать.
 */
void printLargestToSmallest(TreeNode *currentNode);


Tree *createTree()
{
    Tree *newTree = new Tree;
    newTree->root = NULL;
    return newTree;
}

void addTreeLeaf(TreeNode* &currentNode, int x)
{
    TreeNode *newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = x;
    newNode->height = 1;
    currentNode = newNode;
}

bool addTreeNode(Tree *tree, int x)
{
    if (tree->root == NULL)
    {
        addTreeLeaf(tree->root, x);
        return true;
    }
    if (search(tree, x) != NULL)
        return false;
    addTreeNode(tree->root, x);
    return true;
}

void addTreeNode(TreeNode *&currentNode, int x)
{
    if (x < currentNode->value)
    {
        if (currentNode->leftChild != NULL)
        {
            addTreeNode(currentNode->leftChild, x);
            updateHeight(currentNode);
            balance(currentNode);
            updateHeight(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->leftChild, x);
            if (currentNode->height == 1)
                currentNode->height = 2;
        }
    }
    else
    {
        if (currentNode->rightChild != NULL)
        {
            addTreeNode(currentNode->rightChild, x);
            updateHeight(currentNode);
            balance(currentNode);
            updateHeight(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->rightChild, x);
            if (currentNode->height == 1)
                currentNode->height = 2;
        }
    }
}

TreeNode **search(Tree *tree, int x)
{
    return search(tree->root, x);
}

TreeNode **search(TreeNode *&currentNode, int x)
{
    if (currentNode == NULL)
        return NULL;
    if (x == currentNode->value)
        return &currentNode;
    if (x < currentNode->value)
        return search(currentNode->leftChild, x);
    else
        return search(currentNode->rightChild, x);
}

TreeNode **findMin(TreeNode *&currentNode)
{
    if (currentNode->leftChild == NULL)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

bool removeTreeNode(Tree *tree, int x)
{
    if (search(tree, x) == NULL)
        return false;
    removeTreeNode(tree->root, x);
    return true;
}

void removeTreeNode(TreeNode* &currentNode, int x)
{
    if (x < currentNode->value)
    {
        removeTreeNode(currentNode->leftChild, x);
        updateHeight(currentNode);
        balance(currentNode);
        updateHeight(currentNode);
        return;
    }
    else if (x > currentNode->value)
    {
        removeTreeNode(currentNode->rightChild, x);
        updateHeight(currentNode);
        balance(currentNode);
        updateHeight(currentNode);
        return;
    }
    if (currentNode->leftChild == NULL && currentNode->rightChild == NULL)
    {
        delete currentNode;
        currentNode = NULL;
    }
    else if ((currentNode->leftChild != NULL && currentNode->rightChild == NULL)
          || (currentNode->leftChild == NULL && currentNode->rightChild != NULL))
    {
        if (currentNode->leftChild != NULL)
        {
            TreeNode *temporaryNode = currentNode->leftChild;
            delete currentNode;
            currentNode = temporaryNode;
        }
        else
        {
            TreeNode *temporaryNode = currentNode->rightChild;
            delete currentNode;
            currentNode = temporaryNode;
        }
    }
    else
    {
        TreeNode **temporaryNode = findMin(currentNode->rightChild);
        currentNode->value = (*temporaryNode)->value;
        removeTreeNode(*temporaryNode, (*temporaryNode)->value);
    }
}

void clearTree(Tree *tree)
{
    clearTree(tree->root);
    delete tree;
}

void clearTree(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

void updateHeight(TreeNode *currentNode)
{
    if (currentNode->rightChild != NULL && currentNode->leftChild != NULL)
        currentNode->height = max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
    else if (currentNode->rightChild == NULL && currentNode->leftChild == NULL)
        currentNode->height = 1;
    else if (currentNode->rightChild == NULL)
        currentNode->height = currentNode->leftChild->height + 1;
    else
        currentNode->height = currentNode->rightChild->height + 1;
}

void smallLeftRotate(TreeNode *&rootNode)
{
    TreeNode *right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

void smallRightRotate(TreeNode *&rootNode)
{
    TreeNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

void bigLeftRotate(TreeNode *&rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

void bigRightRotate(TreeNode *&rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

void balance(TreeNode *&rootNode)
{
    if (equilibrium(rootNode) == 2)
    {
        if (equilibrium(rootNode->rightChild) >= 0)
            smallLeftRotate(rootNode);
        else
            bigLeftRotate(rootNode);
    }
    else if (equilibrium(rootNode) == -2)
    {
        if (equilibrium(rootNode->leftChild) <= 0)
            smallRightRotate(rootNode);
        else
            bigRightRotate(rootNode);
    }
}

int equilibrium(TreeNode *rootNode)
{
    int left = 0;
    int right = 0;
    if (rootNode->leftChild != NULL)
        left = rootNode->leftChild->height;
    if (rootNode->rightChild != NULL)
        right = rootNode->rightChild->height;
    return right - left;
}

void printTree(TreeNode *currentNode)
{
    printf("(");
    printf("%d ", currentNode->value);
    if (currentNode->leftChild != NULL)
        printTree(currentNode->leftChild);
    else
        printf("null ");
    if (currentNode->rightChild != NULL)
        printTree(currentNode->rightChild);
    else
        printf("null");
    printf(")");
}

void printTree(Tree *tree)
{
    printf("Tree:\n");
    printTree(tree->root);
    printf("\n");
}

void printInfix(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    printInfix(currentNode->leftChild);
    printf("%d ", currentNode->value);
    printInfix(currentNode->rightChild);
}

void printInfix(Tree *tree)
{
    printf("Tree:\n");
    printInfix(tree->root);
    printf("\n");
}

void printLargestToSmallest(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    printLargestToSmallest(currentNode->rightChild);
    printf("%d ", currentNode->value);
    printLargestToSmallest(currentNode->leftChild);
}

void printLargestToSmallest(Tree *tree)
{
    printf("Tree:\n");
    printLargestToSmallest(tree->root);
    printf("\n");
}
