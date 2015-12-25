#include <cstdio>
#include <cstddef>
#include <cmath>
#include "list.h"

struct ListNode{
    double value;
    ListNode *next;
};

struct List{
    ListNode *first;
};
void addAfterGivenNode(ListNode *currentNode, double x);
void addToSortedList(ListNode *currentNode, List &l, double x);
bool equal(double x, double y);

List createList()
{
    List l;
    l.first = NULL;
    addListNode(l, 2147483646);
    addListNode(l, -2147483646);
    return l;
}

void addListNode(List &l, double x)
{
    ListNode *newNode = new ListNode;      //Create new node
    newNode->value = x;
    newNode->next = l.first;               //Bind new node to last first node
    l.first = newNode;                     //New node became the first
}

void addAfterGivenNode(ListNode *currentNode, double x)
{
    ListNode *newNode = new ListNode;
    newNode->value = x;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void addToSortedList(ListNode *currentNode, List &l, double x)
{
    if (currentNode->next != NULL && currentNode->next->value < x)
        return addToSortedList(currentNode->next, l, x);
    addAfterGivenNode(currentNode, x);
}

void addToSortedList(List &l, double x)
{
    addToSortedList(l.first, l, x);
}

bool removeListNode(List &l, double x)
{
    ListNode *currentNode = l.first;
    while (currentNode->next != NULL && equal(currentNode->next->value, x) == false)
        currentNode = currentNode->next;
    if (currentNode->next == NULL)
        return false;
    ListNode *temporaryNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete temporaryNode;
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
    ListNode *currentNode = l.first->next;
    while (currentNode->next != NULL)
    {
        printf("%g\n", currentNode->value);
        currentNode = currentNode->next;
    }
}

void cycleList(List &l)
{
    ListNode *currentNode = l.first;
    do
    {
        currentNode = currentNode->next;
    }
    while (currentNode->next != NULL);
    currentNode->next = l.first;
}

bool equal(double x, double y)
{
    if (x < y)
    {
        double c = x;
        x = y;
        y = c;
    }
    return (x - y < 0.005);
}
