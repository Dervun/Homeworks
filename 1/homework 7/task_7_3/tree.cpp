/*!
 * \brief cpp-шник модуля "Дерево"
 * АВЛ-Дерево, в узлах которого хранятся строки (String)
 */
#include "tree.h"
/*!
 * \brief Ячейка дерева
 * \param value Строка (String)
 * \param height Высота поддерева с корнем в этом узле
 * \param quantity Количество таких ячеек
 * \param leftChild Левый потомок
 * \param rightChild Правый потомок
 */
struct TreeNode{
   String* value;
   int height;
   int quantity;
   TreeNode* leftChild;
   TreeNode* rightChild;
};
/*!
 * \brief Дерево
 * \param root Корень дерева
 */
struct Tree{
    TreeNode* root;
};
/*!
 * \brief Элемент дерева
 * \param value Строка, которая лежит в этом элементе в дереве
 * \param height Высота, которая лежит в этом элементе в дереве
 * \param quantity Количество, которое лежит в этом элементе в дереве
 */
struct ElementsOfTree{
    String* value;
    int heignt;
    int quantity;
};
/*!
 * \brief Добавляет лист
 * \param currentNode Указатель на будущий лист
 * \param x Строка, которую надо добавить в дерево
 * \param quantity Количество использований слова в тексте
 */
void addTreeLeaf(TreeNode* &currentNode, String* x, int quantity);
/*!
 * Добавляет в дерево лист
 * \brief Добавляет лист
 * \param currentNode Указатель на будущий лист
 * \param x Строка, которую надо добавить в дерево
 */
void addTreeLeaf(TreeNode* &currentNode, String *x);
/*!
 * \brief Добавляет в дерево Строку
 * \param currentNode
 * \param x Строка
 * \param quantity
 */
void addTreeNode(TreeNode* &currentNode, String* x, int quantity);
/*!
 * Рекурсивная функция, которая идёт по дереву, ищет место для вставки нового узла, добавляет новый узел
 * \brief Добавляет в дерево Строку
 * \param currentNode Указатель на текущий узел
 * \param x Строка
 */
void addTreeNode(TreeNode *&currentNode, String* x);
/*!
 * Специализированный поиск элемента (для удаления)
 * \brief Поиск элемента в дереве
 * \param tree Дерево
 * \param x Строка
 * \param array Массив указателей на указатели на узлы, лежащие по пути к искомому
 * \param i Счётчик массива, указывающий на первую пустую ячейку
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(Tree *tree, String* x, TreeNode ***array, int &i);
/*!
 * \brief Поиск элемента в дереве
 * \param currentNode Текущий узел
 * \param x Строка
 * \param array Массив указателей на указатели на узлы, лежащие по пути к искомому
 * \param i Счётчик массива, указывающий на первую пустую ячейку
 * \return Указатель на указатель на найдённый элемент
 */
TreeNode **search(TreeNode *&currentNode, String *x, TreeNode ***array, int &i);
/*!
 * Очищает память, занимаемую деревом
 * \brief Удаляет дерево
 * \param currentNode Указатель на вершину поддерева, подлежащего удалению
 */
void clearTree(TreeNode *currentNode);
/*!
 * > Относительно АВЛ-дерева балансировкой вершины называется операция, которая в случае разницы высот левого и правого поддеревьев = 2, изменяет связи предок-потомок в поддереве данной вершины так, что разница становится <= 1, иначе ничего не меняет.
 * > Указанный результат получается вращениями поддерева данной вершины.
 * Функция проверяет, нужна ли балансировка и если нужна, то балансирует
 * \brief Балансировка дерева
 * \param rootNode Узел, от которого идёт балансировка
 */
void balance(TreeNode *&rootNode);
/*!
 * \brief Обновляет высоту данного узла
 * \param currentNode Данный узел
 */
void updateHeight(TreeNode *currentNode);
/*!
 * \brief Малое левое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void smallLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Малое правое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void smallRightRotate(TreeNode *&rootNode);
/*!
 * \brief Большое левое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void bigLeftRotate(TreeNode *&rootNode);
/*!
 * \brief Большое правое вращение
 * \param rootNode Узел, от когорого идёт вращение
 */
void bigRightRotate(TreeNode *&rootNode);
/*!
 * \brief Равновесие данного узла
 * \param rootNode Данный узел
 * \return Разницу между высотами правого и левого вращения
 */
int equilibrium(TreeNode *rootNode);
/*!
 * Рекурсивная функция, запускает себя от левого потомка, потом пишет в файл слово, лежащее в узле,
 * запускает себя от правого потомка, переводит указатель на новую строку.
 * \brief Печатает дерево в файл
 * \param rootNode Корень дерева
 * \param stream Файловый поток
 */
void fprintfTree(TreeNode* rootNode, FILE* stream);
/*!
 * Рекурсивная функция. Вызывает себя от левого потомка, добавляет данные текущего узла в массив,
 * увеличивает индекс для записи в массив, запускает себя от правого потомка.
 * \brief Для вытягивания данных из дерева в массив
 * \param currentNode Текущий узел
 * \param array Массив, в который функция сохраняет данные
 * \param i
 */
void treeToArray(TreeNode* currentNode, ElementsOfTree* array, int &i);

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

void fprintfTree(TreeNode* rootNode, FILE* stream)
{
    if (rootNode == NULL)
        return;
    fprintfTree(rootNode->leftChild, stream);
    char* string = stringToChar(rootNode->value);
    fprintf(stream, "%s - %d\n", string, rootNode->quantity);
    delete []string;
    fprintfTree(rootNode->rightChild, stream);
}

void fprintfTree(Tree* tree, FILE* stream)
{
    fprintfTree(tree->root, stream);
}

void treeToArray(TreeNode* currentNode, ElementsOfTree* array, int &i)
{
    if (currentNode == NULL)
        return;
    treeToArray(currentNode->leftChild, array, i);
    String* s = clone(currentNode->value);
    array[i].value = s;
    array[i].heignt = currentNode->height;
    array[i].quantity = currentNode->quantity;
    i++;
    treeToArray(currentNode->rightChild, array, i);
}

ElementsOfTree* treeToArray(Tree* tree)
{
    int arraySize = pow(2, tree->root->height);
    ElementsOfTree* array = new ElementsOfTree[arraySize];
    for (int i = 0; i < arraySize; i++)
        array[i].value = NULL;
    int i = 0;
    treeToArray(tree->root, array, i);
    return array;
}

int heightOfTree(Tree* tree)
{
    return tree->root->height;
}

bool emptyTree(Tree* tree)
{
    return (tree->root == NULL);
}
