/*!
 * cpp-шник модуля Очередь
 */
#include "queue.h"

/*!
 * \brief Ячейка очереди
 * \param value Значение, хранящееся в ячейке
 * \param next Указатель на следующую
 */
struct QueueNode{
    int value;
    QueueNode *next;
};
/*!
 * Это как стек, только мы кладём наверх, а вынимаем снизу.
 * \brief Очередь
 * \param first Первая ячейка очереди
 * \param last Последняя ячейка очереди
 */
struct Queue{
    QueueNode *first;
    QueueNode *last;
};


Queue *createQueue()
{
    Queue *q = new Queue;
    q->first = NULL;
    q->last = NULL;
    return q;
}

void push(Queue *q, int x)
{
    QueueNode *newNode = new QueueNode;
    newNode->value = x;
    newNode->next = NULL;
    if (q->last == NULL)
        q->last = q->first = newNode;
    else
        q->last->next = q->last = newNode;
}

int pop(Queue *q)
{
    if (q->first == NULL)
        return INT_MAX;
    QueueNode* temporaryNode = q->first;
    q->first = q->first->next;
    if (q->first == NULL)
        q->last = NULL;
    int x = temporaryNode->value;
    delete temporaryNode;
    return x;
}

int showFirst(Queue *q)
{
    return q->first->value;
}

void deleteQueue(Queue *q)
{
    if (q->first == NULL)
    {
        delete q;
        return;
    }
    QueueNode *temporaryNode = q->first->next;
    while (q->first != NULL)
    {
        temporaryNode = q->first->next;
        delete q->first;
        q->first = temporaryNode;
    }
}

bool emptyQueue(Queue *q)
{
    return (q->first == NULL);
}
