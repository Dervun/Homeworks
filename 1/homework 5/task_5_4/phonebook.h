#pragma once
using namespace std;

struct ListNode{
    char name[1000];
    char number[1000];
    ListNode *next;
};

struct List{
    ListNode *first;
};

List fillList();
void addList(List &l, char nam[], char num[]);
char *findPhone(List l, char nam[]);
char *findName(List l, char num[]);
void saveData(List l);
void clearList(List &l);
