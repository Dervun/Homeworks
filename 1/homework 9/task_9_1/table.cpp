#include "table.h"

Table* createTable()
{
    return createTable(103);
}

Table* createTable(int sizeOfTable)
{
    Table* t = new Table;
    t->loadFactor = 0;
    t->quantity = 0;
    t->size = sizeOfTable;
    Tree** trees = new Tree*[sizeOfTable];
    for (int i = 0; i < sizeOfTable; i++)
        trees[i] = createTree();
    t->tree = trees;
    return t;
}

int hashFunction(char* word, int module)
{
    int length = strlen(word);
    unsigned long long result = 0;
    for (int i = 0; i < length && i < 20; i++)
    {
        unsigned long long add = ((int) word[i]) * 7;
        for (int j = 0; j < i; j++)
        {
            add *= 7;
        }
        result += add;
    }
    int result1 = result % module;
    result1 = abs(result1);
    return result1;
}

void rewriteTree(TreeNode* rootNode, Table* t1)
{
    if (rootNode == NULL)
        return;
    rewriteTree(rootNode->leftChild, t1);
    rewriteTree(rootNode->rightChild, t1);
    char* word = stringToChar(rootNode->value);
    addToTable(t1, word, rootNode->quantity);
}

void rewriteTree(Tree* tree, Table* t1)
{
    rewriteTree(tree->root,  t1);
}

void rebuildTable(Table* &t)
{
    printf("Rebilding table..!\n");
    Table *t1 = NULL;
    if (t->size < 103333 || t->size >= 10333333)
        t1 = createTable(t->size * 10 + 3);
    else if (t->size == 103333)
        t1 = createTable(1033313);
    else
        t1 = createTable(10333333);
    for (int i = 0; i < t->size; i++)
    {
        if ((t->tree)[i]->root != NULL)
            rewriteTree((t->tree)[i], t1);
    }
    clearTable(t);
    t = t1;
}

void addToTable(Table* &t, char* word)
{
    String* x = createGivenString(word);
    Tree* detectedTree = findTree(t, word);
    if (search(detectedTree, x) == NULL)
        t->quantity++;
    addTreeNode(detectedTree, x);
    t->loadFactor = (double) t->quantity / t->size;
    if (t->loadFactor > 3)
        rebuildTable(t);
}

void addToTable(Table* &t1, char* word, int quantity)
{
    int length = strlen(word);
    char *clone = new char[length + 1];
    strcpy(clone, word);
    String* x = createGivenString(clone);
    unsigned long long index = hashFunction(clone, t1->size);
    delete []clone;
    t1->quantity++;
    addTreeNode(t1->tree[index], x, quantity);
    t1->loadFactor = (double) t1->quantity / t1->size;
}

void clearTable(Table *t)
{
    for (int i = 0; i < t->size; i++)
    {
        if (t->tree[i]->root != NULL)
        clearTree(t->tree[i]);
    }
    delete []t;
}

Tree* findTree(Table* t, char* buffer)
{
    int index = hashFunction(buffer, t->size);
    return t->tree[index];
}
