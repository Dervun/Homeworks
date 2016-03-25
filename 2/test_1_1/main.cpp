/*!
 * Тест, 1.1 Реализовать очередь с приоритетами в виде шаблонного класса.
 * Очередь должна иметь метод enqueue(), принимающий на вход значение и численный приоритет, и метод dequeue(),
 * возвращающий значение с наивысшим приоритетом и удаляющий его из очереди.
 * Если очередь пуста, deque() должен бросать исключение.
 * Юнит-тесты и документация обязательны.
 */
#include <cstdio>
#include "queue.h"

/*!
 * \brief Напоминалка
 * Функция, которая напоминает пользователю, как давать команды списку.
 * Вызывается каждое четвёртое обращение пользователя к программе.
 */
void reminder()
{
    printf("Menu:\n0 - Exit\n1 - Push\n2 - Pop\n\n");
}

/*!
 * \brief Меню
 * Все команды, которые пользователь может применять к программе.
 */
enum Select{
    exit = 0, ///< Выход из программы
    push, ///< Добавить элемент в очередь
    pop, ///< Взять первый элемент из очереди
};

int main()
{ 
    reminder();
    Select x = exit;
    int input = 0;
    scanf("%d", &input);
    x = (Select) input;
    Queue<int, int>* q = new Queue<int, int>;
    int k = 0;
    while (x != exit)
    {
        k++;
        switch (x)
        {
        case push:
        {
            printf("Enter value to push:\n");
            int newValue = 0;
            scanf("%d", &newValue);
            printf("Enter compare for value:\n");
            int compare = 0;
            scanf("%d", &compare);
            q->enqueue(newValue, compare);
            printf("Value was added :)\n");
            break;
        }
        case pop:
        {
            int value = 0;
            try
            {
                value = q->dequeue();
            }
            catch (int errorCode)
            {
                if (errorCode == 0)
                    printf("Queue is empty :(\n");
            }
            printf("Value == %d :)\n", value);
            break;
        }
        default:
        {
            printf("Error! Incorrect number :(\n");
            break;
        }
        }
        if (k > 3)
        {
            reminder();
            k = 0;
        }
        scanf("%d", &input);
        x = (Select) input;
    }
    delete q;
    printf("End :)\n");
    return 0;
}

