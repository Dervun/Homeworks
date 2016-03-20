#include "listsinglelinked.h"

/*!
 * \brief Создание односвязного списка
 * Длину обнуляю (охранник в счёт не идёт), охранника добавляю.
 */
ListSingleLinked::ListSingleLinked()
{
    index = 0;
    ListNode* security = new ListNode;
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
        ListNode* temporaryNode = first->next;
        first->next = temporaryNode->next;
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
    ListNode* newNode = new ListNode;
    newNode->value = x;
    ListNode* temporary = first->next;
    newNode->next = temporary;
    first->next = newNode;
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
    while (currentNode != nullptr && currentNode->next != nullptr)
    {
        if (currentNode->next->value == x)
        {
            ListNode* afterDetected = currentNode->next->next;
            ListNode* temporaryNode = currentNode->next;
            currentNode->next = afterDetected;
            delete temporaryNode;
            index--;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}
