#pragma once
#include <algorithm>
#include "set.h"
using namespace std;

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
        set = new Set<T>();
    }
    ~Bag()
    {
        delete set;
    }
    /*!
     * \brief Добавление ячейки
     * \param newValue Объект, который надо добавить в множество.
     * \param quantity Количество таких объектов.
     */
    void add(const T &newValue, int quantity) throw (typename Set<T>::AddNodeWithTooLessQuantity);
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
    bool remove(const T &value, int quantity) throw (typename Set<T>::RemoveNodeWithTooManyQuantity);
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
    /*!
     * \brief Пересечение мультимножеств
     * \return Мультимножество, содержащее только те элементы, которые есть в каждом из 2-х мультимножеств (в том количестве, в котором они есть и в первом, и во втором).
     */
    static Bag<T> *intersection(Bag<T> *firstBag, Bag<T> *secondBag);
    /*!
     * \brief Объединение мультимножеств
     * \return Мультимножество, содержащее все элементы первого и второго мультимножеств.
     */
    static Bag<T> *merge(Bag<T> *firstBag, Bag<T> *secondBag);
private:
    Set<T>* set; ///< Указатель на АВЛ-дерево, в котором содержатся все элементы.
};


template <typename T>
void Bag<T>::add(const T &newValue, int quantity) throw (typename Set<T>::AddNodeWithTooLessQuantity)
{
    set->addNode(newValue, quantity);
}

template <typename T>
bool Bag<T>::exists(const T &value)
{
    return set->exists(value);
}

template <typename T>
bool Bag<T>::remove(const T &value, int quantity) throw (typename Set<T>::RemoveNodeWithTooManyQuantity)
{
    return set->removeNode(value, quantity);
}

template <typename T>
int Bag<T>::getHeight()
{
    return set->getHeight();
}

template <typename T>
int Bag<T>::getSize()
{
    return set->getSize();
}

template <typename T>
int Bag<T>::getQuantity(const T &value)
{
    return set->getQuantity(value);
}

template <typename T>
Bag<T> *Bag<T>::intersection(Bag<T> *firstBag, Bag<T> *secondBag)
{
    Bag<T> *result = new Bag<T>();
    QList<QPair<T, int>> *list2 = secondBag->set->setToList();
    for (QPair<T, int> i : *list2)
    {
        if (firstBag->exists(i.first))
            result->add(i.first, min(firstBag->getQuantity(i.first), i.second));
    }
    delete list2;
    return result;
}

template <typename T>
Bag<T> *Bag<T>::merge(Bag<T> *firstBag, Bag<T> *secondBag)
{
    Bag<T> *result = new Bag<T>();
    QList<QPair<T, int>> *list1 = firstBag->set->setToList();
    QList<QPair<T, int>> *list2 = secondBag->set->setToList();
    for (QPair<T, int> i : *list1)
        result->add(i.first, i.second);
    for (QPair<T, int> i : *list2)
        result->add(i.first, i.second);
    delete list1;
    delete list2;
    return result;
}
