#pragma once
#include <algorithm>
#include <stdexcept>
#include "set.h"

template <typename T>
/*!
 * \brief Сумка (мультимножество)
 * Шаблонный класс, представляющий мультимножество.
 * Множество, в котором элементы могут повторяться.
 * Класс асимптотически эффективен по времени и по памяти.
 * Используюется самобалансирующееся дерево для внутреннего представления.
 */
class Bag
{
public:
    class RemoveNodeWithTooManyQuantity : public std::exception
    {
    public:
        const char* details() const noexcept
        {
            return "Error! Attempt to remove element with quantity mote then exists in Bag!";
        }
    };
    class AddNodeWithTooLessQuantity : public std::exception
    {
    public:
        const char* details() const noexcept
        {
            return "Error! Attempt to add element with quantity less then 1!";
        }
    };
    ~Bag()
    {
        clearTree(root);
    }
    /*!
     * \brief Добавление ячейки
     * \param newValue Объект, который надо добавить в множество.
     * \param quantity Количество таких объектов.
     */
    void add(const T &newValue, int quantity) throw (AddNodeWithTooLessQuantity);
    /*!
     * \brief Существование
     * \param value Элемент, существование которого в множестве надо проверить.
     * \return bool - существует, false - не существует.
     */
    bool exists(const T &value);
    /*!
     * \brief Удаление ячейки
     * \param list Список, ячейку с которым нужно удалить.
     * \return true, если ячейка была найдена и удалена; false, если ячейка не была найдена и соответственно удалена.
     */
    bool remove(const T &value, int quantity) throw (RemoveNodeWithTooManyQuantity);
    /*!
     * \brief Высота дерева
     * \return Высоту дерева. Например, если пустое, то 0. Если там только корень, то 1.
     */
    int getHeight();
    /*!
     * \brief Размер множества
     * \return Целое число - количество ячеек в множестве.
     */
    int getSize();
    /*!
     * \brief Количество
     * \param value Сам элемент.
     * \return Количество таких элементов в множестве.
     */
    int getQuantity(const T &value);
private:
    /*!
     * \brief Ячейка дерева, представляющего мультимножество.
     */
    class BagNode
    {
    public:
        BagNode(const T &newValue):
            value(newValue){}
        T value; ///< Значение, которое хранится в ячейке.
        int height = 1;
        int quantity = 1; ///< Количество таких элементов.
        BagNode* leftChild = nullptr; ///< Указатель на левого ребёнка.
        BagNode* rightChild = nullptr; ///< Указатель на правого ребёнка.
    };
    BagNode* root = nullptr;
    int size = 0;

    /*!
     * \brief Добавить ячейку
     * \param currentNode Указатель на текущую ячейку.
     * \param value Элемент, который надо добавить.
     */
    void addNode(BagNode* &currentNode, const T &value, int quantity) throw (AddNodeWithTooLessQuantity);
    /*!
     * \brief Добавление листа
     * \param currentNode Указатель на узел, от которого ведётся добавление.
     * \param value Элемент, который надо добавить.
     */
    void addTreeLeaf(BagNode* &currentNode, const T &value, int quantity) throw (AddNodeWithTooLessQuantity);
    /*!
     * \brief Поиск
     * \param value Элемент, который надо найти в дереве.
     * \return Указатель на указатель на найденную ячейку.
     */
    BagNode **search(const T &value);
    /*!
     * \brief Поиск
     * \param currentNode Указатель на текущую ячейку.
     * \param value Элемент, который надо найти.
     * \return Указатель на указатель на найденную ячейку.
     */
    static BagNode **search(BagNode* &currentNode, const T &value);
    /*!
     * \brief Обновление высоты
     * \param currentNode Текущая ячейка, у которой требуется обновить.
     * Обновление высоты поддерева, образованного данной ячейкой и её детьми.
     */
    static void updateHeight(BagNode* currentNode);
    /*!
     * См. Википедию (ru.wikipedia.org/wiki/АВЛ-дерево#.D0.91.D0.B0.D0.BB.D0.B0.D0.BD.D1.81.D0.B8.D1.80.D0.BE.D0.B2.D0.BA.D0.B0)
     * \brief Малое левое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void smallLeftRotate(BagNode* &rootNode);
    /*!
     * \brief Малое правое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void smallRightRotate(BagNode* &rootNode);
    /*!
     * \brief Большое левое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void bigLeftRotate(BagNode* &rootNode);
    /*!
     * \brief Большое правое вращение
     * \param rootNode Узел, от которого идёт вращение.
     */
    static void bigRightRotate(BagNode* &rootNode);
    /*!
     * \brief Равновесие.
     * \param rootNode Узел, у которого проверяется равновесие.
     * \return Разницу между высотой правого и высотой левого поддеревьев
     */
    static int equilibrium(BagNode *rootNode);
    /*!
     * Если требуется (если модуль равновесия >= 2), происходит балансировка данного поддерева.
     * В зависимости от требований (См. Википедию) производится одно из вращеий.
     * \brief Балансировка
     * \param rootNode Корень поддерева
     */
    static void balance(BagNode* &rootNode);
    /*!
     * \brief Очистка дерева
     * \param currentNode Указатель на текущую ячейкую.
     * Удаляет поддерево, образованное текущей ячейкой и её детьми.
     */
    static void clearTree(BagNode* currentNode);
    /*!
     * \brief Найти минимальный
     * \param currentNode Указатель на текущую ячейку
     * \return Указатель на указатель на искомую (минимальную) ячейку в поддереве с корнем - текущим узлом.
     */
    static BagNode** findMin(BagNode* &currentNode);
    /*!
     * \brief Удалить ячейку дерева
     * \param currentNode Указатель на текущий узел, от которого ведётся удаление.
     * \param value Элемент, который надо удалить из дерева.
     */
    void removeNode(BagNode* &currentNode, const T &value, int quantity) throw (RemoveNodeWithTooManyQuantity);
};

template <typename T>
void Bag<T>::add(const T &newValue, int quantity) throw (AddNodeWithTooLessQuantity)
{
    if (root == nullptr)
        this->addTreeLeaf(root, newValue, quantity);
    else
        this->addNode(root, newValue, quantity);
}

template <typename T>
void Bag<T>::addNode(BagNode *&currentNode, const T &value, int quantity) throw (AddNodeWithTooLessQuantity)
{
    if (value == currentNode->value)
        currentNode->quantity += quantity;
    else if (value < currentNode->value)
    {
        if (currentNode->leftChild != nullptr)
        {
            this->addNode(currentNode->leftChild, value, quantity);
            balance(currentNode);
        }
        else
        {
            this->addTreeLeaf(currentNode->leftChild, value, quantity);
            updateHeight(currentNode);
        }
    }
    else
    {
        if (currentNode->rightChild != nullptr)
        {
            this->addNode(currentNode->rightChild, value, quantity);
            balance(currentNode);
        }
        else
        {
            this->addTreeLeaf(currentNode->rightChild, value, quantity);
            updateHeight(currentNode);
        }
    }
}

template <typename T>
void Bag<T>::addTreeLeaf(BagNode *&currentNode, const T &value, int quantity) throw (AddNodeWithTooLessQuantity)
{
    if (quantity < 1)
        throw AddNodeWithTooLessQuantity();
    BagNode* newNode = new BagNode(value);
    newNode->quantity = quantity;
    size++;
    currentNode = newNode;
}

template <typename T>
typename Bag<T>::BagNode **Bag<T>::search(const T &value)
{
    return search(root, value);
}

template <typename T>
typename Bag<T>::BagNode **Bag<T>::search(BagNode *&currentNode, const T &value)
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
void Bag<T>::updateHeight(BagNode *currentNode)
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
void Bag<T>::smallLeftRotate(BagNode *&rootNode)
{
    BagNode* right = rootNode->rightChild;
    rootNode->rightChild = right->leftChild;
    right->leftChild = rootNode;
    rootNode = right;
    updateHeight(rootNode->leftChild);
    updateHeight(rootNode);
}

template <typename T>
void Bag<T>::smallRightRotate(BagNode *&rootNode)
{
    BagNode *left = rootNode->leftChild;
    rootNode->leftChild = left->rightChild;
    left->rightChild = rootNode;
    rootNode = left;
    updateHeight(rootNode->rightChild);
    updateHeight(rootNode);
}

template <typename T>
void Bag<T>::bigLeftRotate(BagNode *&rootNode)
{
    smallRightRotate(rootNode->rightChild);
    smallLeftRotate(rootNode);
}

template <typename T>
void Bag<T>::bigRightRotate(BagNode *&rootNode)
{
    smallLeftRotate(rootNode->leftChild);
    smallRightRotate(rootNode);
}

template <typename T>
int Bag<T>::equilibrium(BagNode *rootNode)
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
void Bag<T>::balance(BagNode *&rootNode)
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
void Bag<T>::clearTree(BagNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    delete currentNode;
}

template <typename T>
typename Bag<T>::BagNode **Bag<T>::findMin(BagNode *&currentNode)
{
    if (currentNode->leftChild == nullptr)
        return &currentNode;
    return findMin(currentNode->leftChild);
}

template <typename T>
bool Bag<T>::exists(const T &value)
{
    return search(value) != nullptr;
}

template <typename T>
bool Bag<T>::remove(const T &value, const int quantity)  throw (RemoveNodeWithTooManyQuantity)
{
    if (this->search(value) == nullptr)
        return false;
    this->removeNode(root, value, quantity);
    return true;
}

template <typename T>
void Bag<T>::removeNode(BagNode *&currentNode, const T &value, int quantity) throw (RemoveNodeWithTooManyQuantity)
{
    if (value < currentNode->value)
    {
        this->removeNode(currentNode->leftChild, value, quantity);
        balance(currentNode);
        return;
    }
    if (value > currentNode->value)
    {
        this->removeNode(currentNode->rightChild, value, quantity);
        balance(currentNode);
        return;
    }
    if (quantity < currentNode->quantity)
    {
        currentNode->quantity -= quantity;
        return;
    }
    if (quantity > currentNode->quantity)
        throw RemoveNodeWithTooManyQuantity();
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
            BagNode* temporaryNode = currentNode->leftChild;
            delete currentNode;
            size--;
            currentNode = temporaryNode;
        }
        else
        {
            BagNode* temporaryNode = currentNode->rightChild;
            delete currentNode;
            size--;
            currentNode = temporaryNode;
        }
    }
    else
    {
        BagNode** temporaryNode = findMin(currentNode->leftChild);
        currentNode->value = (*temporaryNode)->value;
        currentNode->quantity = (*temporaryNode)->quantity;
        this->removeNode(*temporaryNode, (*temporaryNode)->value, quantity);
    }
}

template <typename T>
int Bag<T>::getHeight()
{
    return root->height;
}

template <typename T>
int Bag<T>::getSize()
{
    return size;
}

template <typename T>
int Bag<T>::getQuantity(const T &value)
{
    BagNode** detectedNode = search(value);
    if (detectedNode == nullptr)
        return 0;
    return (*detectedNode)->quantity;
}
