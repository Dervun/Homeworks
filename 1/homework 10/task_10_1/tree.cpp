#include "tree.h"
#include <cstddef>
#include <string.h>

struct TreeNode{
   char value;
   TreeNode *leftChild;
   TreeNode *rightChild;
};
struct Tree{
    TreeNode *root;
};
void clearTree(TreeNode *currentNode);
void printTree(TreeNode *currentNode);
void fprintTree(FILE* stream, TreeNode *currentNode);
void treeToCode(TreeNode *currentNode, char** code, char* k);


Tree *createTree()
{
    Tree *newTree = new Tree;
    newTree->root = NULL;
    return newTree;
}

Tree* createGivenTree(char symbol)
{
    Tree* newTree = createTree();
    TreeNode* newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = symbol;
    newTree->root = newNode;
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

void printTree(TreeNode *currentNode)
{
    printf("(%c ", currentNode->value);
    if (currentNode->leftChild != NULL)
        printTree(currentNode->leftChild);
    else
        printf("null ");
    if (currentNode->rightChild != NULL)
        printTree(currentNode->rightChild);
    else
        printf("null");
    printf(")");
}

void printTree(Tree *tree)
{
    printf("Tree:\n");
    printTree(tree->root);
    printf("\n");
}

void fprintTree(FILE* stream, TreeNode *currentNode)
{
    fprintf(stream, "(%c ", currentNode->value);
    if (currentNode->leftChild != NULL)
    {
        fprintTree(stream, currentNode->leftChild);
        fprintTree(stream, currentNode->rightChild);
    }
    else
        fprintf(stream, "null");
    fprintf(stream, ")");
}

void fprintTree(FILE* stream, Tree *tree)
{
    fprintTree(stream, tree->root);
}

Tree* mergeTrees(Tree* tree1, Tree* tree2)
{
    Tree* newTree = createGivenTree((char) 7);
    newTree->root->leftChild = tree1->root;
    newTree->root->rightChild = tree2->root;
    delete tree1;
    delete tree2;
    return newTree;
}

void treeToCode(TreeNode *currentNode, char** code, char* k)
{
    if (currentNode->leftChild == NULL)
    {
        int index = (int) currentNode->value;
        strcpy(code[index], k);
    }
    else
    {
        char k1[10];
        strcpy(k1, k);
        int length = strlen(k1);
        k1[length] = '0';
        k1[length + 1] = '\0';
        treeToCode(currentNode->leftChild, code, k1);
        k1[length] = '1';
        treeToCode(currentNode->rightChild, code, k1);
    }
}

void treeToCode(Tree* tree, char** code)
{
    char k[8];
    for (int i = 0; i < 8; i++)
        k[i] = '\0';
    treeToCode(tree->root, code, k);
}