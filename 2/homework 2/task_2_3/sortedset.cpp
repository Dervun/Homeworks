#include <algorithm>
#include "sortedset.h"
using namespace std;


bool SortedSet::addTreeNode(LinkedList *newList)
{
    if (root == nullptr)
    {
        addTreeLeaf(root, newList);
        return true;
    }
    if (search(root, newList) != nullptr)
        return false;
    addTreeNode(root, newList);
    return true;
}

SortedSet::TreeNode** SortedSet::search(LinkedList *list)
{
    return search(root, list);
}

int SortedSet::treeHeight()
{
    if (root == nullptr)
        return 0;
    return root->height;
}

bool SortedSet::removeTreeNode(LinkedList *list)
{
    if (this->search(list) == nullptr)
        return false;
    removeTreeNode(root, list);
    return true;
}

SortedSet::~SortedSet()
{
    clearTree(root);
}

void SortedSet::addTreeLeaf(TreeNode* &currentNode, LinkedList *newList)
{
    TreeNode* newNode = new TreeNode(newList);
    currentNode = newNode;
}

void SortedSet::addTreeNode(SortedSet::TreeNode* &currentNode, LinkedList *newList)
{
    if (ListComparator::compareLists(newList, currentNode->value) == -1)
    {
        if (currentNode->leftChild != nullptr)
        {
            addTreeNode(currentNode->leftChild, newList);
            balance(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->leftChild, newList);
            updateHeight(currentNode);
        }
    }
    else
    {
        if (currentNode->rightChild != nullptr)
        {
            addTreeNode(currentNode->rightChild, newList);
            balance(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->rightChild, newList);
            updateHeight(currentNode);
        }
    }
}

SortedSet::TreeNode** SortedSet::search(SortedSet::TreeNode* &currentNode, LinkedList *list)
{
    if (currentNode == nullptr)
        return nullptr;
    if (ListComparator::compareLists(list, currentNode->value) == 0)
        return &currentNode;
    if (ListComparator::compareLists(list, currentNode->value) == -1)
        return search(currentNode->leftChild, list);
    return search(currentNode->rightChild, list);
}

void SortedSet::updateHeight(SortedSet::TreeNode *currentNode)
{
    if (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr)
        currentNode->height = max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
    else if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr)
        currentNode->height = 1;
    else if (currentNode->rightChild == nullptr)
        currentNode->height = currentNode->leftChild->height + 1;
    else
        currentNode->height = currentNode->rightChild->height + 1;
}

void SortedSet::smallLeftRotate(SortedSet::TreeNode* &rootNode)
{
    TreeNode* right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

void SortedSet::smallRightRotate(SortedSet::TreeNode* &rootNode)
{
    TreeNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

void SortedSet::bigLeftRotate(SortedSet::TreeNode* &rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

void SortedSet::bigRightRotate(SortedSet::TreeNode* &rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

int SortedSet::equilibrium(SortedSet::TreeNode* rootNode)
{
    int left = 0;
    int right = 0;
    if (rootNode->leftChild != NULL)
        left = rootNode->leftChild->height;
    if (rootNode->rightChild != NULL)
        right = rootNode->rightChild->height;
    return right - left;
}

void SortedSet::balance(SortedSet::TreeNode *&rootNode)
{
    updateHeight(rootNode);
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
    updateHeight(rootNode);
}

void SortedSet::clearTree(SortedSet::TreeNode* currentNode)
{
    if (currentNode == nullptr)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

SortedSet::TreeNode** SortedSet::findMin(SortedSet::TreeNode* &currentNode)
{
    if (currentNode->leftChild == nullptr)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

void SortedSet::removeTreeNode(SortedSet::TreeNode* &currentNode, LinkedList *list)
{
    if (ListComparator::compareLists(list, currentNode->value) == -1)
    {
        removeTreeNode(currentNode->leftChild, list);
        balance(currentNode);
        return;
    }
    if (ListComparator::compareLists(list, currentNode->value) == 1)
    {
        removeTreeNode(currentNode->rightChild, list);
        balance(currentNode);
        return;
    }
    if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr)
    {
        delete currentNode;
        currentNode = nullptr;
    }
    else if ((currentNode->leftChild != nullptr && currentNode->rightChild == nullptr) ||
             (currentNode->leftChild == nullptr && currentNode->rightChild != nullptr))
    {
        if (currentNode->leftChild != nullptr)
        {
            TreeNode* temporaryNode = currentNode->leftChild;
            delete currentNode;
            currentNode = temporaryNode;
        }
        else
        {
            TreeNode* temporaryNode = currentNode->rightChild;
            delete currentNode;
            currentNode = temporaryNode;
        }
    }
    else
    {
        TreeNode** temporaryNode = findMin(currentNode->leftChild);
        currentNode->value = (*temporaryNode)->value->getClone();
        removeTreeNode(*temporaryNode, (*temporaryNode)->value);
    }
}

