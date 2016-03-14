#pragma once

/*!
 * \brief Ячейка списка
 * Это базовый класс, он не содержит реализацию, она будет в потомках.
 */
class ListNode
{
public:
    ListNode();
    /*!
     * \brief Деструктор
     * Путой, потому что я не выделяю никакой дополнительной памяти при создании ячейки.
     */
    virtual ~ListNode(){}
    virtual void record(int x) = 0;
    virtual int show() = 0;
    virtual ListNode* viewNext() = 0;
    virtual ListNode* viewPrevious() = 0;
    virtual void linkNext(ListNode* node) = 0;
    virtual void linkPrevoius(ListNode* node) = 0;
protected:
    int value; ///< Значение, которое хранится в ячейке
};

/*!
 * \brief Ячейка односвязного списка
 * В ячейке есть значение, указатель на следующую ячейку.
 * Также функции записи значения, просмотра следующей ячейки, значения ячейки, привязывания слудующей ячейки.
 */
class ListNodeSingleLinked : public ListNode
{
public:
    ListNodeSingleLinked();
    /*!
     * \brief Деструктор
     * Путой, потому что я не выделяю никакой дополнительной памяти при создании ячейки.
     */
    ~ListNodeSingleLinked(){}
    /*!
     * \brief Запись
     * \param x Значение, которое нужно присвоить ячейке
     */
    void record(int x)
    {
        value = x;
    }
    /*!
     * \brief Показывает следующую ячейку
     * \return Указатель на следующую ячейку
     */
    ListNode* viewNext()
    {
        return next;
    }
    /*!
     * \brief То же, что и pop
     * \return Значение, которое хранится в ячейке
     */
    int show()
    {
        return value;
    }
    /*!
     * \brief Привязка
     * \param node ячейка, которую надо привязать, как следующую
     */
    void linkNext(ListNode* node)
    {
        next = node;
    }
protected:
    ListNode* next; ///< Указатель на следующую ячейку
public:
    /*!
     * \brief Заглушка
     * Эта функция является просто заглушкой, потому что в односвязном списке она не используется.
     * \return Нулевой указатель
     */
    ListNode *viewPrevious()
    {
        return nullptr;
    }
    /*!
     * \brief Заглушка
     * Эта функция является просто заглушкой, потому что в односвязном списке она не используется.
     */
    void linkPrevoius(ListNode*){}
};

/*!
 * \brief Ячейка двусвязного списка
 * В ячейке есть значение, указатель на следующую ячейку, на предыдущую ячейку.
 * Также функции записи значения, просмотра следующей, предыдущей ячеек, значения ячейки, привязывания слудующей и предыдущей ячеек.
 */
class ListNodeDoubleLinked : public ListNode
{
public:
    ListNodeDoubleLinked();
    /*!
     * \brief Деструктор
     * Путой, потому что я не выделяю никакой дополнительной памяти при создании ячейки.
     */
    ~ListNodeDoubleLinked(){}
    /*!
     * \brief Запись
     * \param x Число, которое надо записать в ячейку
     * Записывает в ячейку заданное значение.
     */
    void record(int x)
    {
        value = x;
    }
    /*!
     * \brief Показывает следующую ячейку
     * \return Указатель на следующую ячейку
     */
    ListNode* viewNext()
    {
        return next;
    }
    /*!
     * \brief Показывает предыдущую ячейку
     * \return Указатель на предыдущую ячейку
     */
    ListNode* viewPrevious()
    {
        return previous;
    }
    /*!
     * \brief То же, что и pop
     * \return Значение, которое хранится в ячейке
     */
    int show()
    {
        return value;
    }
    /*!
     * \brief Привязка следующей ячейки
     * \param node Указатель на ячейку, которую надо привязать, как следующую
     */
    void linkNext(ListNode* node)
    {
        next = node;
    }
    /*!
     * \brief Привязка предыдущей ячейки
     * \param node Указатель на ячейку, которую надо привязать, как предыдущую
     */
    void linkPrevoius(ListNode* node)
    {
        previous = node;
    }
protected:
    ListNode* next; ///< Указатель на следующий элемент
    ListNode* previous; ///< Указатель на предыдущий элемент
};

/*!
 * \brief Список
 * Это базовый класс, он не содержит реализацию, она будет в потомках.
 * Элементы списка - целые числа.
 * Есть функции добавления элемента, удаления элемента, узнавания длины списка.
 * Так же имеется охранник, стоящий всегда первым в списке.
 */
class List
{
public:
    List(){}
    virtual ~List(){}
    virtual void add(int x) = 0;
    virtual bool remove(int x) = 0;
    virtual int length() = 0;
protected:
    int index; ///< Текущая длина списка.
    ListNode* first; ///< Указатель на первый элемент списка (на охранника).
};

/*!
 * \brief Односвязный список
 * Наследуется от класса List, чтобы к элементам можно было обращаться, как к просто списку (к List).
 */
class ListSingleLinked : public List
{
public:
    ListSingleLinked();
    ~ListSingleLinked();
    void add(int x);
    bool remove(int x);
    /*!
     * \brief Длина списка
     * \return Целое число - длину списка, не считая охранника.
     */
    int length()
    {
        return index;
    }
};

/*!
 * \brief Двусвязный список
 * Наследуется от класса List, чтобы к элементам можно было обращаться, как к просто списку (к List).
 */
class ListDoubleLinked : public List
{
public:
    ListDoubleLinked();
    ~ListDoubleLinked();
    void add(int x);
    bool remove(int x);
    /*!
     * \brief Длина списка
     * \return Целое число - длину списка, не считая охранника.
     */
    int length()
    {
        return index;
    }
};
