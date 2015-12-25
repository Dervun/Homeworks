/*!
 * \brief Header модуля "Дерево"
 * АВЛ-Дерево, в узлах которого хранятся строки (String)
 */
#pragma once
#include "myString.h"
#include <cstddef>
#include <cstdio>
#include <algorithm>
using namespace std;

/*!
 * \brief Ячейка дерева
 * \param value Строка (String)
 * \param height Высота поддерева с корнем в этом узле
 * \param quantity Количество таких ячеек
 * \param leftChild Левый потомок
 * \param rightChild Правый потомок
 */
struct TreeNode
{
   String* value;
   int height;
   int quantity;
   TreeNode* leftChild;
   TreeNode* rightChild;
};

/*!
 * \brief Дерево
 * \param root Корень дерева
 */
struct Tree
{
    TreeNode* root;
};

/*!
 * Создаёт пустое дерево (указатель на корень - NULL), потомков тоже нет. Просто пустое дерево
 * \brief Создаёт дерево
 * \return
 */
Tree *createTree();
/*!
 * \brief Добавляет лист
 * \param currentNode Указатель на будущий лист
 * \param x Строка, которую надо добавить в дерево
 * \param quantity Количество использований слова в тексте
 */
void addTreeLeaf(TreeNode* &currentNode, String* x, int quantity);
/*!
 * Добавляет в дерево лист
 * \brief Добавляет лист
 * \param currentNode Указатель на будущий лист
 * \param x Строка, которую надо добавить в дерево
 */
void addTreeLeaf(TreeNode* &currentNode, String *x);
/*!
 * Запускает функцию добавления Строки от корня дерева
 * \brief Добавляет в дерево Строку
 * \param tree Дерево
 * \param x Строка, которую надо добавить в дерево
 * \param quantity Количество использований слова в тексте
 * \return true - добавлено (такого элемента не было, теперь он есть), false - не добавлено (такой элемент в дереве уже имеется)
 */
bool addTreeNode(Tree *tree, String* x, int quantity);
/*!
 * Запускает функцию добавления Строки от корня дерева, если это необходимо
 * \brief Добавляет в дерево Строку
 * \param tree Дерево
 * \param x Строка, которую надо добавить в дерево
 * \return true - добавлено (такого элемента не было, теперь он есть), false - не добавлено (такой элемент в дереве уже имеется)
 */
bool addTreeNode(Tree *tree, String* x);
/*!
 * \brief Добавляет в дерево Строку
 * \param currentNode
 * \param x Строка
 * \param quantity
 */
void addTreeNode(TreeNode* &currentNode, String* x, int quantity);
/*!
 * Рекурсивная функция, которая идёт по дереву, ищет место для вставки нового узла, добавляет новый узел
 * \brief Добавляет в дерево Строку
 * \param currentNode Указатель на текущий узел
 * \param x Строка
 */
void addTreeNode(TreeNode *&currentNode, String* x);
/*!
 * Простой поиск элемента в дереве
 * \brief Поиск элемента в дереве
 * \param tree Дерево
 * \param x Строка
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(Tree *tree, String *x);
/*!
 * Специализированный поиск элемента (для удаления)
 * \brief Поиск элемента в дереве
 * \param tree Дерево
 * \param x Строка
 * \param array Массив указателей на указатели на узлы, лежащие по пути к искомому
 * \param i Счётчик массива, указывающий на первую пустую ячейку
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(Tree *tree, String* x, TreeNode ***array, int &i);
/*!
 * \brief Поиск элемента в дереве
 * \param currentNode Текущий узел
 * \param x Строка
 * \param array Массив указателей на указатели на узлы, лежащие по пути к искомому
 * \param i Счётчик массива, указывающий на первую пустую ячейку
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(TreeNode *&currentNode, String *x, TreeNode ***array, int &i);
/*!
 * Очищает память, занимаемую деревом
 * \brief Удаляет дерево
 * \param tree Указатель на Дерево
 */
void clearTree(Tree *tree);
/*!
 * Очищает память, занимаемую деревом
 * \brief Удаляет дерево
 * \param currentNode Указатель на вершину поддерева, подлежащего удалению
 */
void clearTree(TreeNode *currentNode);
/*!
 * > Относительно АВЛ-дерева балансировкой вершины называется операция, которая в случае разницы высот левого и правого поддеревьев = 2, изменяет связи предок-потомок в поддереве данной вершины так, что разница становится <= 1, иначе ничего не меняет.
 * > Указанный результат получается вращениями поддерева данной вершины.
 * Функция проверяет, нужна ли балансировка и если нужна, то балансирует
 * \brief Балансировка дерева
 * \param rootNode Узел, от которого идёт балансировка
 */
void balance(TreeNode *&rootNode);
/*!
 * \brief Обновляет высоту данного узла
 * \param currentNode Данный узел
 */
void updateHeight(TreeNode *currentNode);
/*!
 * \brief Малое левое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void smallLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Малое правое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void smallRightRotate(TreeNode *&rootNode);
/*!
 * \brief Большое левое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void bigLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Большое правое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void bigRightRotate(TreeNode *&rootNode);
/*!
 * \brief Равновесие данного узла
 * \param rootNode Данный узел
 * \return Разницу между высотами правого и левого вращения
 */
int equilibrium(TreeNode *rootNode);
