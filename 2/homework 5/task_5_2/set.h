#pragma once
#include <algorithm>

using namespace std;

template <typename T>
/*!
 * \brief Класс множество
 * По сути - шаблонное АВЛ-дерево.
 */
class Set
{
public:
    Set(){}
    Set(Set<T> *set);
    /*!
     * \brief Пересечение множеств
     * \param firstSet Первое мн-во.
     * \param secondSet Второе мн-во.
     * \return Мн-во, содержащее только те элементы, которые есть в каждом из 2-х мн-в.
     */
    static Set<T> *intersectionOfSets(Set<T> *firstSet, Set<T> *secondSet);
    /*!
     * \brief Объединение множеств
     * \param firstSet Первое мн-во.
     * \param secondSet Второе мн-во.
     * \return Мн-во, содержащее все элементы первого и второго мн-в.
     */
    static Set<T> *mergeOfSets(Set<T> *firstSet, Set<T> *secondSet);
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
     * \brief Удаление ячейки
     * \param list Список, ячейку с которым нужно удалить.
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена и соответственно удалена.
     */
    bool removeTreeNode(const T &value);
    /*!
     * \brief Деструктор
     * Освобождает всю память, занятую под дерево, в том числе память, выделенную под списки в ячейках дерева.
     */
    ~Set();
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

    /*!
     * \brief Пересечение множеств
     * \param firstSetNode Текущая ячейка первого множества.
     * \param secondSet Второе множество.
     * \param newSet Новое, итоговое множество, являющееся объединением первого и второго множеств.
     */
    static void intersectionOfSets(TreeNode *firstSetNode, Set<T> *secondSet, Set<T> *newSet);
    /*!
     * \brief Объединение множеств
     * \param firstSetNode Текущая ячейка первого множества.
     * \param newSet Новое, итоговое множество, являющееся объединением первого и второго множеств.
     */
    static void mergeOfSets(TreeNode *firstSetNode, Set<T> *newSet);
    /*!
     * \brief Добавление листа
     * \param currentNode Указатель на узел, от которого ведётся добавление.
     * \param value Элемент, который надо добавить.
     */
    static void addTreeLeaf(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Добавить ячейку
     * \param currentNode Указатель на текущую ячейку.
     * \param value Элемент, который надо добавить.
     * Рекурсивная функция, идёт по дереву в поисках места для добавления.
     */
    static void addTreeNode(TreeNode* &currentNode, const T &value);
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
    static void removeTreeNode(TreeNode* &currentNode, const T &value);
    /*!
     * \brief Клонирование множества
     * \param set Множество.
     * Вспомогательная фукция для конструктора.
     */
    void cloneSet(Set<T> *set);
    /*!
     * \brief Клонирование множества
     * \param currentNode Текущий узел, от которого идёт клонирование.
     * Вспомогательная фукция для конструктора.
     */
    void cloneSet(TreeNode *currentNode);
};

template <typename T>
Set<T>::Set(Set<T> *set)
{
    cloneSet(set);
}

template <typename T>
Set<T> *Set<T>::intersectionOfSets(Set<T> *firstSet, Set<T> *secondSet)
{
    Set<T> *newSet = new Set<T>;
    intersectionOfSets(firstSet->root, secondSet, newSet);
    return newSet;
}

template <typename T>
Set<T> *Set<T>::mergeOfSets(Set<T> *firstSet, Set<T> *secondSet)
{
    Set<T> *newSet = new Set<T>(secondSet);
    mergeOfSets(firstSet->root, newSet);
    return newSet;
}

template <typename T>
bool Set<T>::addTreeNode(const T &newValue)
{
    if (root == nullptr)
    {
        addTreeLeaf(root, newValue);
        return true;
    }
    if (search(root, newValue) != nullptr)
        return false;
    addTreeNode(root, newValue);
    return true;
}

template <typename T>
typename Set<T>::TreeNode **Set<T>::search(const T &value)
{
    return search(root, value);
}

template <typename T>
bool Set<T>::exists(const T &value)
{
    return search(value) != nullptr;
}

template <typename T>
int Set<T>::treeHeight()
{
    if (root == nullptr)
        return 0;
    return root->height;
}

template <typename T>
bool Set<T>::removeTreeNode(const T &value)
{
    if (this->search(value) == nullptr)
        return false;
    removeTreeNode(root, value);
    return true;
}

template <typename T>
void Set<T>::cloneSet(Set<T> *set)
{
    cloneSet(set->root);
}

template <typename T>
Set<T>::~Set()
{
    clearTree(root);
}

template <typename T>
void Set<T>::intersectionOfSets(TreeNode *firstSetNode, Set<T> *secondSet, Set<T> *newSet)
{
    if (firstSetNode)
        {
            if (secondSet->exists(firstSetNode->value))
                newSet->addTreeNode(firstSetNode->value);
            intersectionOfSets(firstSetNode->leftChild, secondSet, newSet);
            intersectionOfSets(firstSetNode->rightChild, secondSet, newSet);
    }
}

template <typename T>
void Set<T>::mergeOfSets(TreeNode *firstSetNode, Set<T> *newSet)
{
    if (firstSetNode != nullptr)
    {
        newSet->addTreeNode(firstSetNode->value);
        mergeOfSets(firstSetNode->leftChild, newSet);
        mergeOfSets(firstSetNode->rightChild, newSet);
    }
}

template <typename T>
void Set<T>::addTreeLeaf(TreeNode *&currentNode, const T &value)
{
    TreeNode* newNode = new TreeNode(value);
    currentNode = newNode;
}

template <typename T>
void Set<T>::addTreeNode(TreeNode *&currentNode, const T &value)
{
    if (value < currentNode->value)
    {
        if (currentNode->leftChild != nullptr)
        {
            addTreeNode(currentNode->leftChild, value);
            balance(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->leftChild, value);
            updateHeight(currentNode);
        }
    }
    else
    {
        if (currentNode->rightChild != nullptr)
        {
            addTreeNode(currentNode->rightChild, value);
            balance(currentNode);
        }
        else
        {
            addTreeLeaf(currentNode->rightChild, value);
            updateHeight(currentNode);
        }
    }
}

template <typename T>
typename Set<T>::TreeNode **Set<T>::search(TreeNode *&currentNode, const T &value)
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
void Set<T>::updateHeight(TreeNode *currentNode)
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
void Set<T>::smallLeftRotate(TreeNode *&rootNode)
{
    TreeNode* right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

template <typename T>
void Set<T>::smallRightRotate(TreeNode *&rootNode)
{
    TreeNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

template <typename T>
void Set<T>::bigLeftRotate(TreeNode *&rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

template <typename T>
void Set<T>::bigRightRotate(TreeNode *&rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

template <typename T>
int Set<T>::equilibrium(TreeNode *rootNode)
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
void Set<T>::balance(TreeNode *&rootNode)
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
void Set<T>::clearTree(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

template <typename T>
typename Set<T>::TreeNode **Set<T>::findMin(TreeNode *&currentNode)
{
    if (currentNode->leftChild == nullptr)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

template <typename T>
void Set<T>::removeTreeNode(TreeNode *&currentNode, const T &value)
{
    if (value < currentNode->value)
    {
        removeTreeNode(currentNode->leftChild, value);
        balance(currentNode);
        return;
    }
    if (value > currentNode->value)
    {
        removeTreeNode(currentNode->rightChild, value);
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
        currentNode->value = (*temporaryNode)->value;
        removeTreeNode(*temporaryNode, (*temporaryNode)->value);
    }
}

template <typename T>
void Set<T>::cloneSet(TreeNode *currentNode)
{
    if (currentNode != nullptr)
    {
        addTreeNode(currentNode->value);
        cloneSet(currentNode->leftChild);
        cloneSet(currentNode->rightChild);
    }
}
