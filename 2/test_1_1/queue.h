#pragma once

template <typename T, typename Cmp>
/*!
 * \brief Очередь с приоритетами
 * Очередь с приоритетами в виде шаблонного класса.
 * Очередь имеет метод enqueue(), принимающий на вход значение и численный приоритет, и метод dequeue(), возвращающий значение с наивысшим приоритетом и удаляющий его из очереди.
 * Если очередь пуста, deque() бросает исключение.
 * \param T Тип значений, которые будут храниться в очереди
 * \param Cmp Тип приоритета
 */
class Queue
{
public:
    /*!
     * \brief Конструктор
     * Пустой, потому что не нужно что-то создавать и выделять дополнительную память.
     */
    Queue(){}
    ~Queue();
    void enqueue(T newValue, Cmp compare);
    T dequeue();
    /*!
     * \brief Размер очереди
     * \return Целое число - размер очереди (количество элементов в очереди)
     */
    int size()
    {
        return index;
    }
private:
    /*!
     * \brief Ячейка очереди
     * Вспомогательный класс, представители этого класса - элементы очереди.
     */
    class QueueNode
    {
    public:
        /*!
         * \brief Конструктор
         * \param newValue Значение, которое нужно присвоить новой ячейке
         * \param compare Приоритет, который нужно присвоить новой ячейке
         */
        QueueNode(T newValue, Cmp compare)
        {
            value = newValue;
            cmp = compare;
        }
        T value; ///< Значение, которое хранится в ячейке
        Cmp cmp; ///< Приоритет, который хранится в ячейке
        QueueNode* next = nullptr; ///< Указатель на следующую ячейку
    };
    QueueNode* first = nullptr; ///< Указатель на первый элемент в очереди (тот, который будет взят первым)
    QueueNode* last = nullptr; ///< Указатель на последний элемент в очереди (тот, который будет взят последним)
    int index = 0; ///< Текущий размер очереди
};

template <typename T, typename Cmp>
/*!
 * \brief Деструктор
 * Удаляет всю очередь, начиная с головы (освобождает память, которую занимают ячейки)
 */
Queue<T, Cmp>::~Queue()
{
    QueueNode* currentNode = first;
    while (currentNode != nullptr)
    {
        QueueNode* nodeToDelete = currentNode;
        currentNode = currentNode->next;
        delete nodeToDelete;
    }
}

template <typename T, typename Cmp>
/*!
 * \brief То же, что push
 * \param newValue Значение, которое надо добавить
 * \param compare Приоритет добавляемого значения
 * Добавляет в очередь новую ячейку по правилам очереди с приоритетами.
 */
void Queue<T, Cmp>::enqueue(T newValue, Cmp compare)
{
    QueueNode* newNode = new QueueNode(newValue, compare);
    if (last == nullptr)
    {
        first = newNode;
        last = newNode;
        index++;
        return;
    }
    if (newNode->cmp > first->cmp)
    {
        newNode->next = first;
        first = newNode;
        index++;
        return;
    }
    QueueNode* currentNode = first;
    while(currentNode->next != nullptr && newNode->cmp <= currentNode->next->cmp)
        currentNode = currentNode->next;
    if (currentNode->next == nullptr)
    {
        currentNode->next = newNode;
        last = newNode;
    }
    else
    {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    index++;
}

template <typename T, typename Cmp>
/*!
 * \brief То же, что pop
 * \return Значение типа T, которое находилось в голове списка
 */
T Queue<T, Cmp>::dequeue()
{
    if (first == nullptr)
        throw 0;
    T valueForReturn = first->value;
    if (first == last)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        QueueNode* nodeToDelete = first;
        first = first->next;
        delete nodeToDelete;
    }
    index--;
    return valueForReturn;
}
