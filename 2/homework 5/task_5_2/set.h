#pragma once
#include <algorithm>
#include "avltree.h"

using namespace std;

template <typename T>
/*!
 * \brief Класс множество
 * Содержит уникальные элементы (не могут повторяться).
 * Создано на основе шаблонного АВЛ-дерева.
 */
class Set
{
public:
    Set()
    {
        tree = new AVLTree<T>;
    }
    ~Set()
    {
        delete tree;
    }

    /*!
     * \brief Добавление
     * \param value Объект, который надо добавить.
     * \return true - если элемент добавлен успешно, false - если элемент добавить не удалось.
     * Повторяющиеся элементы не добавляет.
     */
    bool add(T const &value);
    /*!
     * \brief Удаление ячейки
     * \param value Объект, ячейку с которым нужно удалить.
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена и соответственно удалена.
     */
    bool remove(T const &value);
    /*!
     * \brief Существование
     * \param value Элемент, существование которого в дереве надо проверить.
     * \return bool - существует, false - не существует.
     */
    bool exists(T const &value);
    /*!
     * \brief Размер множества
     * \return Количество ячеек в множестве.
     */
    int getSize();
    /*!
     * \brief Объединение множеств
     * \param firstSet Первое мн-во.
     * \param secondSet Второе мн-во.
     * \return Мн-во, содержащее все элементы первого и второго мн-в.
     */
    static Set<T> *mergeOfSets(Set<T> *set1, Set<T> *set2);
    /*!
     * \brief Пересечение множеств
     * \param firstSet Первое мн-во.
     * \param secondSet Второе мн-во.
     * \return Мн-во, содержащее только те элементы, которые есть в каждом из 2-х мн-в.
     */
    static Set<T> *intersectionOfSets(Set<T> *set1, Set<T> *set2);

private:
    AVLTree<T> *tree;
};

template <typename T>
bool Set<T>::add(const T &value)
{
    return tree->addTreeNode(value);
}

template <typename T>
bool Set<T>::remove(const T &value)
{
    return tree->removeTreeNode(value);
}

template <typename T>
bool Set<T>::exists(T const &value)
{
    return tree->exists(value);
}

template <typename T>
int Set<T>::getSize()
{
    return tree->getSize();
}

template <typename T>
Set<T> *Set<T>::mergeOfSets(Set<T> *set1, Set<T> *set2)
{
    Set<T> *newSet = new Set<T>;
    newSet->tree = AVLTree<T>::mergeOfTrees(set1->tree, set2->tree);
    return newSet;
}

template <typename T>
Set<T> *Set<T>::intersectionOfSets(Set<T> *set1, Set<T> *set2)
{
    Set<T> *newSet = new Set<T>;
    newSet->tree = AVLTree<T>::intersectionOfTrees(set1->tree, set2->tree);
    return newSet;
}

