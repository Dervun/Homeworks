#include "listsinglelinked.h"

ListSingleLinked::ListSingleLinked()
{
    index = 0;
    ListNode* security = new ListNode;
    first = security;
}

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

void ListSingleLinked::add(int x)
{
    ListNode* newNode = new ListNode;
    newNode->value = x;
    ListNode* temporary = first->next;
    newNode->next = temporary;
    first->next = newNode;
    index++;
}

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
