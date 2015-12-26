/*!
 * \brief Header модуля "Дерево"
 * АВЛ-Дерево, в узлах которого хранятся строки (String)
 */
#pragma once
#include "myString.h"
#include <cstddef>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode;
struct Tree;
struct ElementsOfTree;

/*!
 * Создаёт пустое дерево (указатель на корень - NULL), потомков тоже нет. Просто пустое дерево
 * \brief Создаёт дерево
 * \return Указатель на созданное дерево
 */
Tree *createTree();
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
 * Простой поиск элемента в дереве
 * \brief Поиск элемента в дереве
 * \param tree Дерево
 * \param x Строка
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(Tree *tree, String *x);
/*!
 * Очищает память, занимаемую деревом
 * \brief Удаляет дерево
 * \param tree Указатель на Дерево
 */
void clearTree(Tree *tree);
/*!
 * Запускает рекурсивную функцию печати дерева в файл.
 * \brief Печатает дерево в файл
 * \param tree Дерево
 * \param stream Файловый поток
 */
void fprintfTree(Tree* tree, FILE* stream);
/*!
 * Функция записывает в массив все данные из дерева в порядке возрастания их ключей.
 * Массив создаётся по ходу дела, динамическим выделением памяти.
 * \brief Вытягивание данных из дерева в массив
 * \param tree Дерево
 * \return Указатель на массив
 */
ElementsOfTree* treeToArray(Tree* tree);
/*!
 * \brief Высота дерева
 * \param tree Дерево
 * \return Высоту дерева
 */
int heightOfTree(Tree* tree);
/*!
 * \brief Проверка дерева на пустоту
 * \param tree Дерево
 * \return true - пустое (корень - NULL), false - не пустое (есть хотя бы корень).
 */
bool emptyTree(Tree* tree);
