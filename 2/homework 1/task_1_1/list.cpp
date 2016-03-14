#include "list.h"

/*!
 * \brief Создание односвязного списка
 * Длину обнуляю (охранник в счёт не идёт), охранника добавляю.
 */
ListSingleLinked::ListSingleLinked()
{
    index = 0;
    ListNode* security = new ListNodeSingleLinked;
    first = security;
}

/*!
 * \brief Деструктор
 * Удаляет все ячейки, которые были в списке, в том числе охранника.
 */
ListSingleLinked::~ListSingleLinked()
{
    for (int i = 0; i < index; i++)
    {
        ListNode* temporaryNode = first->viewNext();
        first->linkNext(temporaryNode->viewNext());
        delete temporaryNode;
    }
    delete first;
}

/*!
 * \brief Добавление
 * \param x Значение, которое надо добавить
 * Функция добавляет ячейку с заданным значением в голову списка (сразу после охранника).
 */
void ListSingleLinked::add(int x)
{
    ListNode* newNode = new ListNodeSingleLinked;
    newNode->record(x);
    ListNode* temporary = first->viewNext();
    newNode->linkNext(temporary);
    first->linkNext(newNode);
    index++;
}

/*!
 * \brief Удаление
 * \param x Значение, ячейку с которым надо удалить
 * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена
 * Из-за того, что в списке могут храниться несколько ячеек с одним и тем же значением, возникает неоднозначность удаления.
 * Я удаляю ячейку, ближайшую к голове списка
 */
bool ListSingleLinked::remove(int x)
{
    ListNode* currentNode = first;
    while (currentNode != nullptr && currentNode->viewNext() != nullptr)
    {
        if (currentNode->viewNext()->show() == x)
        {
            ListNode* afterDetected = currentNode->viewNext()->viewNext();
            ListNode* temporaryNode = currentNode->viewNext();
            currentNode->linkNext(afterDetected);
            delete temporaryNode;
            index--;
            return true;
        }
        currentNode = currentNode->viewNext();
    }
    return false;
}

/*!
 * \brief Создание и обнуление элемента списка
 */
ListNode::ListNode()
{
    value = 0;
}

/*!
 * \brief Создание и обнуление элемента односвязного списка
 */
ListNodeSingleLinked::ListNodeSingleLinked()
{
    value = 0;
    next = nullptr;
}

/*!
 * \brief Создание и обнуление элемента двусвязного списка
 */
ListNodeDoubleLinked::ListNodeDoubleLinked()
{
    value = 0;
    next = nullptr;
    previous = nullptr;
}

/*!
 * \brief Создание односвязного списка
 * Длину обнуляю (охранник в счёт не идёт), охранника добавляю.
 */
ListDoubleLinked::ListDoubleLinked()
{
    index = 0;
    ListNode* security = new ListNodeDoubleLinked;
    first = security;
}

/*!
 * \brief Деструктор
 * Удаляет все ячейки, которые были в списке, в том числе охранника.
 */
ListDoubleLinked::~ListDoubleLinked()
{
    for (int i = 0; i < index; i++)
    {
        ListNode* temporaryNode = first->viewNext();
        first->linkNext(temporaryNode->viewNext());
        delete temporaryNode;
    }
    delete first;
}

/*!
 * \brief Добавление
 * \param x Значение, которое надо добавить
 * Функция добавляет ячейку с заданным значением в голову списка (сразу после охранника).
 */
void ListDoubleLinked::add(int x)
{
    ListNode* newNode = new ListNodeDoubleLinked;
    newNode->record(x);
    ListNode* temporary = first->viewNext();
    newNode->linkNext(temporary);
    newNode->linkPrevoius(first);
    first->linkNext(newNode);
    index++;
}

/*!
 * \brief Удаление
 * \param x Значение, ячейку с которым надо удалить
 * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена
 * Из-за того, что в списке могут храниться несколько ячеек с одним и тем же значением, возникает неоднозначность удаления.
 * Я удаляю ячейку, ближайшую к голове списка
 */
bool ListDoubleLinked::remove(int x)
{
    ListNode* currentNode = first;
    while (currentNode != nullptr && currentNode->viewNext() != nullptr)
    {
        if (currentNode->viewNext()->show() == x)
        {
            ListNode* afterDetected = currentNode->viewNext()->viewNext();
            ListNode* temporaryNode = currentNode->viewNext();
            currentNode->linkNext(afterDetected);
            afterDetected->linkPrevoius(currentNode);
            delete temporaryNode;
            index--;
            return true;
        }
        currentNode = currentNode->viewNext();
    }
    return false;
}
