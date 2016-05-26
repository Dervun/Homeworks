#pragma once
#include "set.h"

template <typename T>
/*!
 * \brief Сумка (мультимножество)
 * Шаблонный класс, представляющий мультимножество.
 * Множество, в котором элементы могут повторяться.
 * Класс асимптотически эффективен по времени и по памяти.
 * Используюется самобалансирующееся дерево для внутреннего представления.
 */
class Bag
{
public:
    Bag()
    {
        tree = new Set<T>();
    }
    ~Bag()
    {
        delete tree;
    }
    /*!
     * \brief Добавление ячейки
     * \param newValue Объект, который надо добавить в множество.
     * \param quantity Количество таких объектов.
     */
    void addNode(const T &newValue, int quantity) throw (typename Set<T>::AddNodeWithTooLessQuantity);
    /*!
     * \brief Существование
     * \param value Элемент, существование которого в множестве надо проверить.
     * \return bool - существует, false - не существует.
     */
    bool exists(const T &value);
    /*!
     * \brief Удаление ячейки
     * \param list Список, ячейку с которым нужно удалить.
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена и соответственно удалена.
     */
    bool removeNode(const T &value, int quantity) throw (typename Set<T>::RemoveNodeWithTooManyQuantity);
    /*!
     * \brief Высота дерева
     * \return Высоту дерева. Например, если пустое, то 0. Если там только корень, то 1.
     */
    int getHeight();
    /*!
     * \brief Размер множества
     * \return Целое число - количество ячеек в множестве.
     */
    int getSize();
    /*!
     * \brief Количество
     * \param value Сам элемент.
     * \return Количество таких элементов в множестве.
     */
    int getQuantity(const T &value);
private:
    Set<T>* tree; ///< Указатель на АВЛ-дерево, в котором содержатся все элементы.
};


template <typename T>
void Bag<T>::addNode(const T &newValue, int quantity) throw (typename Set<T>::AddNodeWithTooLessQuantity)
{
    tree->addNode(newValue, quantity);
}

template <typename T>
bool Bag<T>::exists(const T &value)
{
    return tree->exists(value);
}

template <typename T>
bool Bag<T>::removeNode(const T &value, int quantity) throw (typename Set<T>::RemoveNodeWithTooManyQuantity)
{
    return tree->removeNode(value, quantity);
}

template <typename T>
int Bag<T>::getHeight()
{
    return tree->getHeight();
}

template <typename T>
int Bag<T>::getSize()
{
    return tree->getSize();
}

template <typename T>
int Bag<T>::getQuantity(const T &value)
{
    return tree->getQuantity(value);
}
