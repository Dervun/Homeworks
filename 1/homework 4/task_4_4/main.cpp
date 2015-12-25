/*!
 * > Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
 * > 0 - exit;
 * > 1 - add a value to sorted list;
 * > 2 - remove a value from sorted list;
 * > 3 - print list.
 * > Все операции должны сохранять сортированность. Начинаем с пустого списка.
 * > Список должен быть оформлен отдельным модулем.
*/
#include <cstdio>
#include "list.h"
struct ListNode{
    double value;
    ListNode *next;
};
struct List{
    ListNode *first;
};
enum Select{
    exit = 0,
    add,
    removeValue,
    print
};

void reminder()
{
    printf("0 - exit;\n");
    printf("1 - add a value to sorted list;\n");
    printf("2 - remove a value from sorted list;\n");
    printf("3 - print list.\n");
}

main()
{
    Select x = add;
    List l = createList();
    reminder();
    int y = 0;
    scanf("%d", &y);
    x = (Select) y;
    int j = 1;
    while (x != exit)
    {
        j++;
        switch (x)
        {
            case add:
            {
                printf("Enter the value:\n");
                float n = 0;
                scanf("%g", &n);
                addToSortedList(l, n);
                printf("Value has added :)\n");
                break;
            }
            case removeValue:
            {
                printf("Enter the value:\n");
                float n = 0;
                scanf("%g", &n);
                bool haveRemove = removeListNode(l, n);
                if (haveRemove)
                {
                    printf("Value has removed :)\n");
                }
                else
                {
                    printf("Value has not found in list :(\n");
                }
                break;
            }
            case print:
            {
                printf("List:\n\n");
                printList(l);
                break;
            }
            default:
            {
                printf("0 - exit;\n");
                printf("1 - add a value to sorted list;\n");
                printf("2 - remove a value from sorted list;\n");
                printf("3 - print list.\n");
                break;
            }
        }
        if (j > 4)
        {
            reminder();
            j = 1;
        }
        scanf("%d", &y);
        x = (Select) y;
    }
    removeTotalList(l);
    printf("Program is complete :)\n");
}
