#include <fstream>
#include <cstddef>
#include <string.h>
#include <cstdio>
#include "phonebook.h"

char *findPhone(List l, char nam[])
{
    ListNode *findNode = l.first;
    while (strcmp(findNode->name, nam) != 0 && findNode->next)     //Until name is coincidence and till next node exists
    {
        findNode = findNode->next;
    }
    if (strcmp(findNode->name, nam) == 0)                          //If name has found
    {
        return findNode->number;
    }
    else
    {
        return NULL;
    }
}
char *findName(List l, char num[])
{
    ListNode *findNode = l.first;
    while (strcmp(findNode->number, num) != 0 && findNode->next)
    {
        findNode = findNode->next;
    }
    if (strcmp(findNode->number, num) == 0)
    {
        return findNode->name;
    }
    else
    {
        return NULL;
    }
}

List fillList()
{
    ifstream fin;
    fin.open("Phonebook.txt");          //Open file for reading
    List l;                             //Create list
    l.first = NULL;
    if (fin.is_open())
    {
        //printf("Debug printing:\n{\n");
        while (!fin.eof())                  //Until end of file, ...
        {
            char name[1000];                //first buffer
            char number[1000];              //second buffer
            fin >> name >> number;          //Read name and number separated by a space from file
            //printf("%s %s\n", name, number);
            addList(l, name, number);       //Add new node of list, record name and number
        }
        //printf("}\n");
    }
    fin.close();                        //Close file
    return l;
}

void addList(List &l, char nam[], char num[])
{
    ListNode *node = new ListNode;      //Create new node
    int length1 = strlen(nam);
    int length2 = strlen(num);
    for (int i = 0; i <= length1; i++)
    {
        node->name[i] = nam[i];
    }
    for (int i = 0; i <= length2; i++)
    {
        node->number[i] = num[i];
    }
    node->next = l.first;               //Bind new node to last first node
    l.first = node;                     //New node became the first
}

void saveData(List l)
{
    ofstream fout;
    fout.open("Phonebook.txt");          //Open file for record data
    ListNode *currentNode = l.first;
    do
    {
        fout << currentNode->name << " " << currentNode->number << endl;
        currentNode = currentNode->next;
    }
    while (currentNode);
    fout.close();                        //Close file
}

void clearList(List &l)                  //Clear memory
{
    ListNode *currentNode = l.first;
    while (currentNode)
    {
        ListNode *temporaryNode = currentNode->next;
        delete currentNode;
        currentNode = temporaryNode;
    }
}
