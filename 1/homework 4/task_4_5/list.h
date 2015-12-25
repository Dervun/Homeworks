#pragma once
#include <cstdio>
#include <cstddef>

struct ListNode{
    int value;
    ListNode* next;
    ListNode* previous;
};

struct List{
    ListNode* first;
    ListNode* current;
};

List createList();
void addListNode(List &l, int x);
void addToSortedList(List &l, int x);
bool removeListNode(List &l, int x);
void removeTotalList(List &l);
void printList(List &l);
void loopList(List &l);
void reversePrintList(List l);
int lengthLoopList(List l);
int showFirstNode(List l);
void currentToFirst(List &l);
void moveCurrent(List &l, int step);
void removePreviousNode(List &l);
