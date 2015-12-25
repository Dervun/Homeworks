/*!
 * АВЛ-дерево (сбалансированное по высоте двоичное дерево поиска:
 * для каждой его вершины высота её двух поддеревьев различается не более чем на 1.)
*/
#include "tree.h"
#include <cstdio>

enum Select{
    exit = 0,
    add,
    removeValue,
    existence,
    print,
    printSmLg,
    printLgSm
};

void reminder()
{
    printf("\nReminder:\n");
    printf("0 - exit\n1 - add number\n2 - remove\n3 - exists?\n4 - print tree (parent left_child right_child)\n");
    printf("5 - print tree from the smallest to the lagest\n6 - print tree from the lagest to the smallest\n");
}

main()
{
    reminder();
    Tree *tree = createTree();
    Select x = add;
    int y = 0;
    scanf("%d", &y);
    x = (Select) y;
    int j = 0;
    while (x != exit)
    {
        j++;
        if (x == add)
        {
            int value = 0;
            printf("Enter value to add:\n");
            scanf("%d", &value);
            if (addTreeNode(tree, value))
                printf("Value has been added (%d) :)\n", value);
            else
                printf("Value hasn't been added because tree have it :(\n");
        }
        else if (x == removeValue)
        {
            int value = 0;
            printf("Enter value to remove:\n");
            scanf("%d", &value);
            if (removeTreeNode(tree, value))
                printf("Value has been removed :)\n");
            else
                printf("Value hasn't been removed because it hasn't found :(\n");
        }
        else if (x == existence)
        {
            int value;
            printf("Enter value to search:\n");
            scanf("%d", &value);
            if (search(tree, value) != NULL)
                printf("The value exists :)\n");
            else
                printf("The value doesn't exist :(\n");

        }
        else if (x == print)
            printTree(tree);
        else if (x == printSmLg)
            printInfix(tree);
        else if (x == printLgSm)
            printLargestToSmallest(tree);
        else
            reminder();
        if (j > 3)
        {
            reminder();
            j = 0;
        }
        scanf("%d", &y);
        x = (Select) y;
    }
    clearTree(tree);
}
