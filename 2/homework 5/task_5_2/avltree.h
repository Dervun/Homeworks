#pragma once
#include <algorithm>

using namespace std;

template <typename T>
/*!
 * \brief АВЛ-дерево.
 * По сути - шаблонное АВЛ-дерево.
 */
class AVLTree
{
public:
    AVLTree(){}
    AVLTree(AVLTree<T> *tree);

    /*!
     * \brief Пересечение Деревьев
     * \param firstTree Первое дерево.
     * \param secondTree Второе дерево.
     * \return Дерево, содержащее только те элементы, которые есть в каждом из 2-х деревьев.
     */
    static AVLTree<T> *intersectionOfTrees(AVLTree<T> *firstTree, AVLTree<T> *secondTree);
    /*!
     * \brief Объединение Деревьев
     * \param firstTree Первое дерево.
     * \param secondTree Второе дерево.
     * \return Дерево, содержащее все элементы первого и второго деревьев.
     */
    static AVLTree<T> *mergeOfTrees(AVLTree<T> *firstTree, AVLTree<T> *secondTree);
    /*!
     * \brief Добавление ячейки
     * \param newValue Элемент, который надо добавить в дерево.
     * \return true - если элемент добавлен успешно, false - если элемент добавить не удалось.
     * Повторяющиеся элементы не добавляет.
     */
    bool addTreeNode(const T &newValue);
    /*!
     * \brief Существование
     * \param value Элемент, существование которого в дереве надо проверить.
     * \return bool - существует, false - не существует.
     */
    bool exists(const T &value);
    /*!
     * \brief Высота дерева
     * \return Высоту дерева. Если пустое, то 0. Если там только голова, то 1.
     */
    int treeHeight();
    /*!
     * \brief Размер дерева
     * \return Количество ячеек в дереве.
     */
    int getSize()
    {
        return size;
    }
    /*!
     * \brief Удаление ячейки
     * \param value Объект, ячейку с которым нужно удалить.
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена и соответственно удалена.
     */
    bool removeTreeNode(const T &value);
    /*!
     * \brief Деструктор
     * Освобождает всю память, занятую под дерево, в том числе память, выделенную под списки в ячейках дерева.
     */
    ~AVLTree();
private:
    /*!
     * \brief Ячейка дерева
     */
    class TreeNode
    {
    public:
        TreeNode(const T newValue):
            value(newValue){}
        T value; ///< Значение, который хранится в ячейке.
        int height = 1; ///< Высота поддерева, которое образует данная вершина со своими детьми.
        TreeNode* leftChild = nullptr; ///< Указатель на левого ребёнка.
        TreeNode* rightChild = nullptr; ///< Указатель на правого ребёнка.
    };
    TreeNode* root = nullptr; ///< Указатель на корень дерева.
    int size = 0;

    /*!
     * \brief Пересечение множеств
     * \param firstSetNode Текущая ячейка первого множества.
     * \param secondSet Второе множество.
     * \param newSet Новое, итоговое множество, являющееся объединением первого и второго множеств.
     */
    static void intersectionOfTrees(TreeNode *firstTreeNode, AVLTree<T> *secondTree, AVLTree<T> *newTree);
    /*!
     * \brief Объединение множеств
     * \param firstSetNode Текущая ячейка первого множества.
     * \param newSet Новое, итоговое множество, являющееся объединением первого и второго множеств.
     */
    static void mergeOfTrees(TreeNode *firstTreeNode, AVLTree<T> *newTree);
    /*!
     * \brief Добавление листа
     * \param currentNode Указатель на узел, от которого ведётся добавление.
     * \param value Элемент, который надо добавить.
     */
    void addTreeLeaf(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Добавить ячейку
     * \param currentNode Указатель на текущую ячейку.
     * \param value Элемент, который надо добавить.
     * Рекурсивная функция, идёт по дереву в поисках места для добавления.
     */
    void addTreeNode(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Поиск
     * \param value Элемент, который надо найти в дереве.
     * \return Указатель на указатель на найденную ячейку.
     */
    TreeNode **search(const T &value);
    /*!
     * \brief Поиск
     * \param currentNode Указатель на текущую ячейку.
     * \param value Элемент, который надо найти.
     * \return Указатель на указатель на найденную ячейку.
     */
    static TreeNode **search(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Обновление высоты
     * \param currentNode Текущая ячейка, у которой требуется обновить.
     * Обновление высоты поддерева, образованного данной ячейкой и её детьми.
     */
    static void updateHeight(TreeNode* currentNode);
    /*!
     * См. Википедию (ru.wikipedia.org/wiki/АВЛ-дерево#.D0.91.D0.B0.D0.BB.D0.B0.D0.BD.D1.81.D0.B8.D1.80.D0.BE.D0.B2.D0.BA.D0.B0)
     * \brief Малое левое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void smallLeftRotate(TreeNode* &rootNode);
    /*!
     * \brief Малое правое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void smallRightRotate(TreeNode* &rootNode);
    /*!
     * \brief Большое левое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void bigLeftRotate(TreeNode* &rootNode);
    /*!
     * \brief Большое правое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void bigRightRotate(TreeNode* &rootNode);
    /*!
     * \brief Равновесие.
     * \param rootNode Узел, у которого проверяется равновесие.
     * \return Разницу между высотой правого и высотой левого поддеревьев
     */
    static int equilibrium(TreeNode *rootNode);
    /*!
     * Если требуется (если модуль равновесия >= 2), происходит балансировка данного поддерева.
     * В зависимости от требований (См. Википедию) производится одно из вращеий.
     * \brief Балансировка
     * \param rootNode Корень поддерева
     */
    static void balance(TreeNode* &rootNode);
    /*!
     * \brief Очистка дерева
     * \param currentNode Указатель на текущую ячейкую.
     * Удаляет поддерево, образованное текущей ячейкой и её детьми.
     */
    static void clearTree(TreeNode* currentNode);
    /*!
     * \brief Найти минимальный
     * \param currentNode Указатель на текущую ячейку
     * \return Указатель на указатель на искомую (минимальную) ячейку в поддереве с корнем - текущим узлом.
     */
    static TreeNode** findMin(TreeNode* &currentNode);
    /*!
     * \brief Удалить ячейку дерева
     * \param currentNode Указатель на текущий узел, от которого ведётся удаление.
     * \param value Элемент, который надо удалить из дерева.
     */
    void removeTreeNode(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Клонирование множества
     * \param set Множество.
     * Вспомогательная фукция для конструктора.
     */
    void cloneTree(AVLTree<T> *tree);
    /*!
     * \brief Клонирование множества
     * \param currentNode Текущий узел, от которого идёт клонирование.
     * Вспомогательная фукция для конструктора.
     */
    void cloneTree(TreeNode *currentNode);
};

template <typename T>
AVLTree<T>::AVLTree(AVLTree<T> *tree)
{
    cloneTree(tree);
}

template <typename T>
AVLTree<T> *AVLTree<T>::intersectionOfTrees(AVLTree<T> *firstTree, AVLTree<T> *secondTree)
{
    AVLTree<T> *newSet = new AVLTree<T>;
    intersectionOfTrees(firstTree->root, secondTree, newSet);
    return newSet;
}

template <typename T>
AVLTree<T> *AVLTree<T>::mergeOfTrees(AVLTree<T> *firstTree, AVLTree<T> *secondTree)
{
    AVLTree<T> *newTree = new AVLTree<T>(secondTree);
    mergeOfTrees(firstTree->root, newTree);
    return newTree;
}

template <typename T>
bool AVLTree<T>::addTreeNode(const T &newValue)
{
    if (root == nullptr)
    {
        this->addTreeLeaf(root, newValue);
        return true;
    }
    if (search(root, newValue) != nullptr)
        return false;
    this->addTreeNode(root, newValue);
    return true;
}

template <typename T>
typename AVLTree<T>::TreeNode **AVLTree<T>::search(const T &value)
{
    return search(root, value);
}

template <typename T>
bool AVLTree<T>::exists(const T &value)
{
    return search(value) != nullptr;
}

template <typename T>
int AVLTree<T>::treeHeight()
{
    if (root == nullptr)
        return 0;
    return root->height;
}

template <typename T>
bool AVLTree<T>::removeTreeNode(const T &value)
{
    if (this->search(value) == nullptr)
        return false;
    this->removeTreeNode(root, value);
    return true;
}

template <typename T>
void AVLTree<T>::cloneTree(AVLTree<T> *tree)
{
    cloneTree(tree->root);
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    clearTree(root);
}

template <typename T>
void AVLTree<T>::intersectionOfTrees(TreeNode *firstTreeNode, AVLTree<T> *secondTree, AVLTree<T> *newTree)
{
    if (firstTreeNode)
        {
            if (secondTree->exists(firstTreeNode->value))
                newTree->addTreeNode(firstTreeNode->value);
            intersectionOfTrees(firstTreeNode->leftChild, secondTree, newTree);
            intersectionOfTrees(firstTreeNode->rightChild, secondTree, newTree);
    }
}

template <typename T>
void AVLTree<T>::mergeOfTrees(TreeNode *firstTreeNode, AVLTree<T> *newTree)
{
    if (firstTreeNode != nullptr)
    {
        newTree->addTreeNode(firstTreeNode->value);
        mergeOfTrees(firstTreeNode->leftChild, newTree);
        mergeOfTrees(firstTreeNode->rightChild, newTree);
    }
}

template <typename T>
void AVLTree<T>::addTreeLeaf(TreeNode *&currentNode, const T &value)
{
    TreeNode* newNode = new TreeNode(value);
    size++;
    currentNode = newNode;
}

template <typename T>
void AVLTree<T>::addTreeNode(TreeNode *&currentNode, const T &value)
{
    if (value < currentNode->value)
    {
        if (currentNode->leftChild != nullptr)
        {
            this->addTreeNode(currentNode->leftChild, value);
            balance(currentNode);
        }
        else
        {
            this->addTreeLeaf(currentNode->leftChild, value);
            updateHeight(currentNode);
        }
    }
    else
    {
        if (currentNode->rightChild != nullptr)
        {
            this->addTreeNode(currentNode->rightChild, value);
            balance(currentNode);
        }
        else
        {
            this->addTreeLeaf(currentNode->rightChild, value);
            updateHeight(currentNode);
        }
    }
}

template <typename T>
typename AVLTree<T>::TreeNode **AVLTree<T>::search(TreeNode *&currentNode, const T &value)
{
    if (currentNode == nullptr)
        return nullptr;
    if (value == currentNode->value)
        return &currentNode;
    if (value < currentNode->value)
        return search(currentNode->leftChild, value);
    return search(currentNode->rightChild, value);
}

template <typename T>
void AVLTree<T>::updateHeight(TreeNode *currentNode)
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

template <typename T>
void AVLTree<T>::smallLeftRotate(TreeNode *&rootNode)
{
    TreeNode* right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

template <typename T>
void AVLTree<T>::smallRightRotate(TreeNode *&rootNode)
{
    TreeNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

template <typename T>
void AVLTree<T>::bigLeftRotate(TreeNode *&rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

template <typename T>
void AVLTree<T>::bigRightRotate(TreeNode *&rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

template <typename T>
int AVLTree<T>::equilibrium(TreeNode *rootNode)
{
    int left = 0;
    int right = 0;
    if (rootNode->leftChild != NULL)
        left = rootNode->leftChild->height;
    if (rootNode->rightChild != NULL)
        right = rootNode->rightChild->height;
    return right - left;
}

template <typename T>
void AVLTree<T>::balance(TreeNode *&rootNode)
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

template <typename T>
void AVLTree<T>::clearTree(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

template <typename T>
typename AVLTree<T>::TreeNode **AVLTree<T>::findMin(TreeNode *&currentNode)
{
    if (currentNode->leftChild == nullptr)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

template <typename T>
void AVLTree<T>::removeTreeNode(TreeNode *&currentNode, const T &value)
{
    if (value < currentNode->value)
    {
        this->removeTreeNode(currentNode->leftChild, value);
        balance(currentNode);
        return;
    }
    if (value > currentNode->value)
    {
        this->removeTreeNode(currentNode->rightChild, value);
        balance(currentNode);
        return;
    }
    if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr)
    {
        delete currentNode;
        size--;
        currentNode = nullptr;
    }
    else if ((currentNode->leftChild != nullptr && currentNode->rightChild == nullptr) ||
             (currentNode->leftChild == nullptr && currentNode->rightChild != nullptr))
    {
        if (currentNode->leftChild != nullptr)
        {
            TreeNode* temporaryNode = currentNode->leftChild;
            delete currentNode;
            size--;
            currentNode = temporaryNode;
        }
        else
        {
            TreeNode* temporaryNode = currentNode->rightChild;
            delete currentNode;
            size--;
            currentNode = temporaryNode;
        }
    }
    else
    {
        TreeNode** temporaryNode = findMin(currentNode->leftChild);
        currentNode->value = (*temporaryNode)->value;
        this->removeTreeNode(*temporaryNode, (*temporaryNode)->value);
    }
}

template <typename T>
void AVLTree<T>::cloneTree(TreeNode *currentNode)
{
    if (currentNode != nullptr)
    {
        addTreeNode(currentNode->value);
        cloneTree(currentNode->leftChild);
        cloneTree(currentNode->rightChild);
    }
}
