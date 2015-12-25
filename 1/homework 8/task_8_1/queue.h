/*!
 * header модуля Очередь
 */
#pragma once
#include <cstdio>
#include <limits.h>

struct QueueNode;
struct Queue;

/*!
 * \brief Создаёт пустую очередь
 * \return Указатель на созданную очередь
 */
Queue *createQueue();
/*!
 * \brief Положить в очередь
 * \param q Очередь
 * \param x То, что надо положить в очередь
 */
void push(Queue *q, int x);
/*!
 * \brief Взять первый элемент из очереди
 * \param q Очередь
 * \return Зачение первого элемента очереди
 */
int pop(Queue *q);
/*!
 * \brief Показывает значение первого элемента очереди
 * \param q Очередь
 * \return Значение первого элемента очереди
 */
int showFirst(Queue *q);
/*!
 * Освобождение памяти, занятой под очередь
 * \brief Удаление очереди
 * \param q Очередь
 */
void deleteQueue(Queue *q);
/*!
 * \brief Проверка очереди на пустоту
 * \param q Очередь
 * \return Если в очереди есть хотя бы один элемент, то возвращаемое значение - false. Если нет элементов, то true.
 */
bool emptyQueue(Queue *q);
