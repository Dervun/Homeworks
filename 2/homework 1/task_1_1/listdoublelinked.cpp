#include "listdoublelinked.h"

ListDoubleLinked::ListDoubleLinked()
{
    index = 0;
    ListNode* security = new ListNode;
    first = security;
}

ListDoubleLinked::~ListDoubleLinked()
{
    for (int i = 0; i < index; i++)
    {
        ListNode* temporaryNode = first->next;
        first->next = temporaryNode->next;
        delete temporaryNode;
    }
    delete first;
}

void ListDoubleLinked::add(int x)
{
    ListNode* newNode = new ListNode;
    newNode->value = x;
    ListNode* temporary = first->next;
    newNode->next = temporary;
    newNode->previous = first;
    first->next = newNode;
    index++;
}

bool ListDoubleLinked::remove(int x)
{
    ListNode* currentNode = first;
    while (currentNode != nullptr && currentNode->next != nullptr)
    {
        if (currentNode->next->value == x)
        {
            ListNode* afterDetected = currentNode->next->next;
            ListNode* temporaryNode = currentNode->next;
            currentNode->next = afterDetected;
            if (afterDetected)
                afterDetected->previous = currentNode;
            delete temporaryNode;
            index--;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}
