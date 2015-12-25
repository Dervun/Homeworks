#include "calculator.h"
#include "tree.h"
#include <cstddef>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>

struct TreeNode
{
    char value[50];
    TreeNode* leftChild;
    TreeNode* rightChild;
};
struct Tree
{
    TreeNode* root;
};

void clearTree(TreeNode *currentNode);
void getValue(TreeNode *currentNode, char *stringTree, int &i, int q);
void treeToPostfix(TreeNode* currentNode, char *postfix, int &i);
void printInfix(TreeNode *currentNode);
void readTree(char *stringTree, TreeNode *&currentNode);


Tree *createTree()
{
    Tree *newTree = new Tree;
    newTree->root = NULL;
    return newTree;
}

void clearTree(Tree *tree)
{
    clearTree(tree->root);
    delete tree;
}

void clearTree(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

void getValue(TreeNode *currentNode, char *stringTree, int &i, int q)
{
    while (isdigit(stringTree[i]) || stringTree[i] == '.')
    {
        currentNode->value[q] = stringTree[i];
        q++;
        i++;
    }
    currentNode->value[q] = '\0';
}

void treeToPostfix(TreeNode* currentNode, char *postfix, int &i)
{
    if (currentNode == NULL)
        return;
    if (currentNode->leftChild != NULL)
    {
        treeToPostfix(currentNode->leftChild, postfix, i);
        treeToPostfix(currentNode->rightChild, postfix, i);
    }
    int length = strlen(currentNode->value);
    for (int j = 0; j < length; j++)
    {
        postfix[i] = currentNode->value[j];
        i++;
    }
    postfix[i] = ' ';
    i++;
}

char *treeToPostfix(Tree* tree)
{
    char *postfix = new char[100000];
    int i = 0;
    treeToPostfix(tree->root, postfix, i);
    postfix[i] = '\0';
    return postfix;
}

void printInfix(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    bool needBracket1 = false;
    bool needSpace = false;
    if (currentNode->leftChild != NULL && currentNode->leftChild->leftChild != NULL)
    {
        printf("(");
        needBracket1 = true;
    }
    if (currentNode->leftChild != NULL)
    {
        printInfix(currentNode->leftChild);
        needSpace = true;
    }
    if (needBracket1)
        printf(")");
    if (needSpace)
        printf(" ");
    int length = strlen(currentNode->value);
    for (int i = 0; i < length; i++)
        printf("%c", currentNode->value[i]);
    if (needSpace)
        printf(" ");
    bool needBracket2 = false;
    if (currentNode->rightChild != NULL && currentNode->rightChild->leftChild != NULL)
    {
        printf("(");
        needBracket2 = true;
    }
    if (currentNode->rightChild != NULL)
        printInfix(currentNode->rightChild);
    if (needBracket2)
        printf(")");
}

void printInfix(Tree* tree)
{
    printf("Tree:\n");
    printInfix(tree->root);
}

Tree* readTree(char* stringTree)
{
    Tree* tree = createTree();
    readTree(stringTree, tree->root);
    return tree;
}

void readTree(char *stringTree, TreeNode* &currentNode)
{
    int length = strlen(stringTree);
    int i = 0;
    TreeNode *newNode = new TreeNode;
    currentNode = newNode;
    bool haveParent = false;
    while (!haveParent)
    {
        if (stringTree[i] == '+' || stringTree[i] == '-' || stringTree[i] == '*' || stringTree[i] == '/')
        {
            currentNode->value[0] = stringTree[i];
            currentNode->value[1] = '\0';
            i++;
            haveParent = true;
        }
        else if (isdigit(stringTree[i]))
        {
            getValue(currentNode, stringTree, i, 0);
            break;
        }
        else if (stringTree[i] == '-' && isdigit(stringTree[i + 1]))
        {
            currentNode->value[0] = '-';
            i++;
            getValue(currentNode, stringTree, i, 1);
            break;
        }
        else
            i++;
    }
    i++;
    if (i < length && haveParent)
    {
        char *child1 = new char[10000];
        char *child2 = new char[10000];
        if (isdigit(stringTree[i]))
        {
            int j = 0;
            while (isdigit(stringTree[i]) || stringTree[i] == '.')
            {
                child1[j] = stringTree[i];
                i++;
                j++;
            }
            child1[j] = '\0';
        }
        else if (stringTree[i] == '-' && isdigit(stringTree[i + 1]))
        {
            int j = 0;
            while (isdigit(stringTree[i]) || stringTree[i] == '.')
            {
                child1[j] = stringTree[i];
                i++;
                j++;
            }
            child1[j] = '\0';
        }
        else
        {
            int begining = i;
            bool endOfChild1 = false;
            int k = 0;
            while (!endOfChild1)
            {
                if (stringTree[i] == '(')
                {
                    k++;
                    i++;
                }
                else if (stringTree[i] == ')')
                {
                    k--;
                    i++;
                }
                else
                    i++;
                if (k <= 0)
                    endOfChild1 = true;
            }
            int q = 0;
            int j = begining;
            while (j < i)
            {
                child1[q] = stringTree[j];
                q++;
                j++;
            }
            child1[q] = '\0';
        }
        int k = 0;
        for ( ; i < length - 1; i++)
        {
            child2[k] = stringTree[i];
            k++;
        }
        if (stringTree[i] != ')')
        {
            child2[k] = stringTree[i];
            i++;
            k++;
        }
        child2[k] = '\0';
        readTree(child1, currentNode->leftChild);
        readTree(child2, currentNode->rightChild);
        delete []child1;
        delete []child2;
    }
}
