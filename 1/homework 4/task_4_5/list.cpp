#include "list.h"

void removeCurrentNode(List &l, ListNode* currentNode);

List createList()
{
    List l;
    l.first = NULL;
    l.current = NULL;
    return l;
}

void addListNode(List &l, int x)
{
    ListNode *newNode = new ListNode;      //Create new node
    newNode->value = x;
    newNode->next = l.first;               //Bind new node to last first node
    if (newNode->next != NULL)
    {
        newNode->next->previous = newNode;
    }
    l.first = newNode;                     //New node became the first
    l.current = l.first;
    newNode->previous = NULL;
}

void addToSortedList(List &l, int x)
{
    ListNode *currentNode = l.first;
    while (currentNode->next != NULL && currentNode->next->value < x)
    {
        currentNode = currentNode->next;
    }
    if (currentNode == l.first)
    {
        addListNode(l, x);
    }
    else if (currentNode->next == NULL)
    {
        ListNode *newNode = new ListNode;
        currentNode->next = newNode;
        newNode->previous = currentNode;
        newNode->next = NULL;
        newNode->value = x;
    }
    else
    {
        ListNode *newNode = new ListNode;
        newNode->value = x;
        newNode->next = currentNode->next;
        newNode->previous = currentNode;
        currentNode->next->previous = newNode;
        currentNode->next = newNode;
    }
}

bool removeListNode(List &l, int x)
{
    if (l.first == NULL)
        return false;
    ListNode *currentNode = l.first;
    while (currentNode != NULL && currentNode->value != x)
        currentNode = currentNode->next;
    if (currentNode == NULL)
        return false;
    removeCurrentNode(l, currentNode);
    return true;
}

void removeTotalList(List &l)
{
    do
    {
        ListNode *temporaryNode = l.first;
        l.first = l.first->next;
        delete temporaryNode;
    }
    while (l.first != NULL);
}

void printList(List &l)
{
    ListNode *currentNode = l.first;
    while (currentNode != NULL)
    {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    }
}

void loopList(List &l)
{
    ListNode *currentNode = l.first;
    do
    {
        currentNode = currentNode->next;
    }
    while (currentNode->next != NULL);
    currentNode->next = l.first;
    l.first->previous = currentNode;
}

void reversePrintList(List l)
{
    ListNode *currentNode = l.first;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    while (currentNode != NULL)
    {
        printf("%c", currentNode->value);
        currentNode = currentNode->previous;
    }
}

int lengthLoopList(List l)
{
    int x = l.first->value;
    int result = 0;
    ListNode *currentNode = l.first;
    do
    {
        currentNode = currentNode->next;
        result++;
    }
    while (currentNode->value != x);
    return result;
}

int showFirstNode(List l)
{
    int x = l.first->value;
    return x;
}

void currentToFirst(List &l)
{
    l.current = l.first;
}

void moveCurrent(List &l, int step)
{
    for (int i = 0; i < step; i++)
        l.current = l.current->next;
}

void removePreviousNode(List &l)
{
    removeCurrentNode(l, l.current->previous);
    l.first = l.current;
}

void removeCurrentNode(List &l, ListNode* currentNode)
{
    ListNode* temporaryNode = currentNode;
    if (currentNode->previous != NULL)
        currentNode->previous->next = currentNode->next;
    else
        l.first = currentNode->next;
    if (currentNode->next != NULL)
        currentNode->next->previous = currentNode->previous;
    delete temporaryNode;
}
