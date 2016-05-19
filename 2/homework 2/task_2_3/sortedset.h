#pragma once
#include "linkedlist.h"

/*!
 * \brief Класс Отсортированное множество
 * По сути - АВЛ дерево, хранящее в себе сортированные списки, ключ - длина списка.
 */
class SortedSet
{
public:
    /*!
     * \brief Ячейка дерева
     */
    class TreeNode
    {
    public:
        /*!
         * \brief Конструктор TreeNode
         * \param newList Указатель на список, который будет помещён в ячейку.
         * Функция создаёт и помещает в ячейку идентичный входному список.
         */
        TreeNode(ListComparable* newList)
        {
            value = newList->getClone();
        }
        ListComparable* value; ///< Список, который хранится в ячейке.
        int height = 1; ///< Высота поддерева, которое образует данная вершина со своими детьми.
        TreeNode* leftChild = nullptr; ///< Указатель на левого ребёнка.
        TreeNode* rightChild = nullptr; ///< Указатель на правого ребёнка.
        ~TreeNode()
        {
            delete value;
        }
    };
    /*!
     * \brief Добавление ячейки
     * \param newList Указатель на список, который надо добавить в дерево.
     * \return true - если элемент добавлен успешно, false - если элемент добавить не удалось.
     * Повторяющиеся элементы не добавляет.
     */
    bool addTreeNode(ListComparable* newList);
    /*!
     * \brief Поиск
     * \param list Лист, который надо найти в дереве.
     * \return Указатель на указатель на найденную ячейку.
     */
    TreeNode** search(ListComparable* list);
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
    bool removeTreeNode(ListComparable* list);
    /*!
     * \brief Деструктор
     * Освобождает всю память, занятую под дерево, в том числе память, выделенную под списки в ячейках дерева.
     */
    ~SortedSet();
private:
    TreeNode* root = nullptr; ///< Указатель на корень дерева.
    /*!
     * \brief Добавление листа
     * \param currentNode Указатель на узел, от которого ведётся добавление.
     * \param newList Указатель на список, который надо добавить.
     */
    static void addTreeLeaf(TreeNode* &currentNode, ListComparable* newList);
    /*!
     * \brief Добавить ячейку
     * \param currentNode Указатель на текущую ячейку.
     * \param newList Указатель на список, который надо добавить.
     * Рекурсивная функция, идёт по дереву в поисках места для добавления.
     */
    static void addTreeNode(TreeNode* &currentNode, ListComparable* newList);
    /*!
     * \brief Поиск
     * \param currentNode Указатель на текущую ячейку.
     * \param list Указатель на список, который надо найти.
     * \return Указатель на указатель на найденную ячейку.
     */
    static TreeNode** search(TreeNode* &currentNode, ListComparable* list);
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
     * \param list Список, который надо удалить из дерева.
     */
    static void removeTreeNode(TreeNode* &currentNode, ListComparable *list);
};
