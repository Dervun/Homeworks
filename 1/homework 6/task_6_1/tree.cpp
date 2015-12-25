#include "tree.h"
#include <cstddef>
#include <cstdio>

struct TreeNode
{
   int value;
   TreeNode *leftChild;
   TreeNode *rightChild;
};
struct Tree
{
    TreeNode *root;
};
void addTreeLeaf(TreeNode* &currentNode, int x);
bool addTreeNode(TreeNode *currentNode, int x);
TreeNode **search(TreeNode *&currentNode, int x);
bool removeTreeNode(TreeNode *&detectedNode);
TreeNode **findMin(TreeNode *&currentNode);
void clearTree(TreeNode *currentNode);
void printTree(TreeNode *currentNode);
void printInfix(TreeNode *currentNode);
void printLargestToSmallest(TreeNode *currentNode);


Tree *createTree()
{
    Tree *newTree = new Tree;
    newTree->root = NULL;
    return newTree;
}

void addTreeLeaf(TreeNode* &currentNode, int x)
{
    TreeNode *newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = x;
    currentNode = newNode;
}

bool addTreeNode(Tree *tree, int x)
{
    if (tree->root == NULL)
    {
        addTreeLeaf(tree->root, x);
        return true;
    }
    return addTreeNode(tree->root, x);
}

bool addTreeNode(TreeNode *currentNode, int x)
{
    if (x == currentNode->value)
        return false;
    if (x < currentNode->value)
    {
        if (currentNode->leftChild != NULL)
            return addTreeNode(currentNode->leftChild, x);
        else
        {
            addTreeLeaf(currentNode->leftChild, x);
            return true;
        }
    }
    else
    {
        if (currentNode->rightChild != NULL)
            return addTreeNode(currentNode->rightChild, x);
        else
        {
            addTreeLeaf(currentNode->rightChild, x);
            return true;
        }
    }
}

TreeNode **search(Tree *tree, int x)
{
    return search(tree->root, x);
}


TreeNode **search(TreeNode *&currentNode, int x)
{
    if (currentNode == NULL)
        return NULL;
    if (x == currentNode->value)
        return &currentNode;
    if (x < currentNode->value)
        return search(currentNode->leftChild, x);
    else
        return search(currentNode->rightChild, x);
}

TreeNode **findMin(TreeNode *&currentNode)
{
    if (currentNode->leftChild == NULL)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

bool removeTreeNode(Tree *tree, int x)
{
    if (tree->root == NULL)
        return false;
    TreeNode **pointerToDetectedNode = search(tree, x);
    if (pointerToDetectedNode == NULL)
        return false;
    return removeTreeNode(*pointerToDetectedNode);
}

bool removeTreeNode(TreeNode *&detectedNode)
{
    if (detectedNode->leftChild == NULL && detectedNode->rightChild == NULL)
    {
        delete detectedNode;
        detectedNode = NULL;
        return true;
    }
    else if ((detectedNode->leftChild != NULL && detectedNode->rightChild == NULL)
          || (detectedNode->leftChild == NULL && detectedNode->rightChild != NULL))
    {
        if (detectedNode->leftChild != NULL)
        {
            TreeNode *temporaryNode = detectedNode->leftChild;
            delete detectedNode;
            detectedNode = temporaryNode;
        }
        else
        {
            TreeNode *temporaryNode = detectedNode->rightChild;
            delete detectedNode;
            detectedNode = temporaryNode;
        }
        return true;
    }
    else
    {
        TreeNode **temporaryNode = findMin(detectedNode->rightChild);
        detectedNode->value = (*temporaryNode)->value;
        return removeTreeNode(*temporaryNode);
    }
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
    printf("(");
    printf("%d ", currentNode->value);
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

void printInfix(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    printInfix(currentNode->leftChild);
    printf("%d ", currentNode->value);
    printInfix(currentNode->rightChild);
}

void printInfix(Tree *tree)
{
    printf("Tree:\n");
    printInfix(tree->root);
    printf("\n");
}

void printLargestToSmallest(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return;
    printLargestToSmallest(currentNode->rightChild);
    printf("%d ", currentNode->value);
    printLargestToSmallest(currentNode->leftChild);
}

void printLargestToSmallest(Tree *tree)
{
    printf("Tree:\n");
    printLargestToSmallest(tree->root);
    printf("\n");
}
