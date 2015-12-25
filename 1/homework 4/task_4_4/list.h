#pragma once

struct ListNode;
struct List;
List createList();
void addListNode(List &l, double x);
void addToSortedList(List &l, double x);
bool removeListNode(List &l, double x);
void removeTotalList(List &l);
void printList(List &l);
void cycleList(List &l);
