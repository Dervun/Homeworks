#include <climits>
#include "linkedlist.h"

LinkedList::LinkedList()
{
    ListNode* securityMinimal = new ListNode;
    securityMinimal->value = INT_MIN;
    ListNode* securityMaximal = new ListNode;
    securityMaximal->value = INT_MAX;
    securityMinimal->next = securityMaximal;
    securityMaximal->previous = securityMinimal;
    first = securityMinimal;
}

LinkedList::~LinkedList()
{
    for (int i = 0; i <= listLength; i++)
    {
        ListNode* temporaryNode = first->next;
        first->next = temporaryNode->next;
        delete temporaryNode;
    }
    delete first;
}

void LinkedList::add(int x)
{
    ListNode* currentNode = first;
    while (x > currentNode->next->value)
        currentNode = currentNode->next;
    ListNode* newNode = new ListNode;
    newNode->value = x;
    newNode->next = currentNode->next;
    newNode->previous = currentNode;
    currentNode->next->previous = newNode;
    currentNode->next = newNode;
    listLength++;
}

bool LinkedList::remove(int x)
{
    if (listLength == 0)
        return false;
    ListNode* currentNode = first;
    while (currentNode->next->value != INT_MAX)
    {
        if (currentNode->next->value == x)
        {
            ListNode* afterDetected = currentNode->next->next;
            ListNode* temporaryNode = currentNode->next;
            currentNode->next = afterDetected;
            if (afterDetected)
                afterDetected->previous = currentNode;
            delete temporaryNode;
            listLength--;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

LinkedList *LinkedList::getClone()
{
    LinkedList* newLinkedList = new LinkedList;
    ListNode* currentNode = first->next;
    for (int i = 0; i < listLength; i++)
    {
        newLinkedList->add(currentNode->value);
        currentNode = currentNode->next;
    }
    return newLinkedList;
}
