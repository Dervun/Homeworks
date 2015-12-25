/*!
 * \brief cpp-шник модуля "Дерево"
 * АВЛ-Дерево, в узлах которого хранятся строки (String)
 */
#include "tree.h"

Tree *createTree()
{
    Tree *newTree = new Tree;
    newTree->root = NULL;
    return newTree;
}

void addTreeLeaf(TreeNode* &currentNode, String* x, int quantity)
{
    TreeNode *newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = x;
    newNode->height = 1;
    newNode->quantity = quantity;
    currentNode = newNode;
}

void addTreeLeaf(TreeNode* &currentNode, String* x)
{
    addTreeLeaf(currentNode, x, 1);
}

bool addTreeNode(Tree *tree, String* x, int quantity)
{
    if (tree->root == NULL)
    {
        addTreeLeaf(tree->root, x, quantity);
        return true;
    }
    search(tree, x);
    addTreeNode(tree->root, x, quantity);
    return true;
}

bool addTreeNode(Tree *tree, String* x)
{
    if (tree->root == NULL)
    {
        addTreeLeaf(tree->root, x);
        return true;
    }
    TreeNode** detected = search(tree, x);
    if (detected != NULL)
    {
        (*detected)->quantity++;
        return false;
    }
    addTreeNode(tree->root, x);
    return true;
}

void addTreeNode(TreeNode* &currentNode, String* x, int quantity)
{
    if (compareString(x, currentNode->value) == smaller)
    {
        if (currentNode->leftChild != NULL)
        {
            addTreeNode(currentNode->leftChild, x, quantity);
            updateHeight(currentNode);
            balance(currentNode);
            updateHeight(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->leftChild, x, quantity);
            if (currentNode->height == 1)
                currentNode->height = 2;
        }
    }
    else
    {
        if (currentNode->rightChild != NULL)
        {
            addTreeNode(currentNode->rightChild, x, quantity);
            updateHeight(currentNode);
            balance(currentNode);
            updateHeight(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->rightChild, x, quantity);
            if (currentNode->height == 1)
                currentNode->height = 2;
        }
    }
}

void addTreeNode(TreeNode* &currentNode, String* x)
{
    addTreeNode(currentNode,  x, 1);
}

TreeNode **search(Tree *tree, String* x)
{
    TreeNode **array[1000];
    int i = 0;
    return search(tree->root, x, array, i);
}

TreeNode **search(Tree *tree, String *x, TreeNode ***array, int &i)
{
    return search(tree->root, x, array, i);
}

TreeNode **search(TreeNode *&currentNode, String* x, TreeNode ***array, int &i)
{
    if (currentNode == NULL)
        return NULL;
    if (compareString(x, currentNode->value) == equivalent)
        return &currentNode;
    if (compareString(x, currentNode->value) == smaller)
    {
        array[i] = &currentNode;
        i++;
        return search(currentNode->leftChild, x, array, i);
    }
    else
    {
        array[i] = &currentNode;
        i++;
        return search(currentNode->rightChild, x, array, i);
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
    removeString(currentNode->value);
    delete currentNode;
}

void updateHeight(TreeNode *currentNode)
{
    if (currentNode->rightChild != NULL && currentNode->leftChild != NULL)
        currentNode->height = max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
    else if (currentNode->rightChild == NULL && currentNode->leftChild == NULL)
        currentNode->height = 1;
    else if (currentNode->rightChild == NULL)
        currentNode->height = currentNode->leftChild->height + 1;
    else
        currentNode->height = currentNode->rightChild->height + 1;
}

void smallLeftRotate(TreeNode *&rootNode)
{
    TreeNode *right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

void smallRightRotate(TreeNode *&rootNode)
{
    TreeNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

void bigLeftRotate(TreeNode *&rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

void bigRightRotate(TreeNode *&rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

void balance(TreeNode *&rootNode)
{
    if (equilibrium(rootNode) == 2)
    {
        if (equilibrium(rootNode->rightChild) >= 0)
            smallLeftRotate(rootNode);
        else
            bigLeftRotate(rootNode);
    }
    else if (equilibrium(rootNode) == -2)
    {
        if (equilibrium(rootNode->leftChild) <= 0)
            smallRightRotate(rootNode);
        else
            bigRightRotate(rootNode);
    }
}

int equilibrium(TreeNode *rootNode)
{
    int left = 0;
    int right = 0;
    if (rootNode->leftChild != NULL)
        left = rootNode->leftChild->height;
    if (rootNode->rightChild != NULL)
        right = rootNode->rightChild->height;
    return right - left;
}
