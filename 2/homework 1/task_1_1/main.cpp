/*!
 * Разработать интерфейс, представляющий структуру данных "связный список".
 * Реализовать этот список двумя разными способами (односвязный/двусвязный, на массиве/на указателях и т.п.) на основе полученного интерфейса.
 */
#include <cstdio>
#include "listtest.h"

/*!
 * \brief Напоминалка
 * Функция, которая напоминает пользователю, как давать команды списку.
 * Вызывается каждое четвёртое обращение пользователя к программе.
 */
void reminder()
{
    printf("Menu:\n0 - Exit\n1 - Add node\n2 - Remove node\n3 - Length of list\n\n");
}

/*!
 * \brief Меню
 * Все команды, которые пользователь может применять к программе.
 */
enum Select{
    endOfProgram = 0, ///< Выход из программы
    addNode, ///< Добавить элемент в список
    removeNode, ///< Удалить элемент из списка
    lengthOfList ///< Узнать длину спика
};

/*!
 * \brief Выбор вида списка
 * \return Указатель на выбранный список
 * Вспомогательная функция, нужна, чтобы пользователь выбрал, какой он список хочет использовать - односвязный или двусвязный.
 */
List* singleOrDouble()
{
    List* list;
    bool isCorrect = false;
    while (!isCorrect)
    {
        printf("Single-linked or double-linked?\nEnter 1 or 2 respectively:\n");
        int type = 0;
        scanf("%d", &type);
        if (type == 1)
        {
            list = new ListSingleLinked;
            isCorrect = true;
        }
        else if (type == 2)
        {
            list = new ListDoubleLinked;
            isCorrect = true;
        }
        else
            printf("Error! Expected 1 or 2\n");
    }
    return list;
}

/*!
 * \brief Добавление
 * \param list Указатель на список, в который надо добавлять
 * Вспомогательная функция, чтобы уменьшить main.
 * Общается с пользователем.
 */
void auxiliaryAdd(List* list)
{
    printf("Enter integer value:\n");
    int value;
    scanf("%d", &value);
    list->add(value);
    printf("Value was added :)\n");
}

/*!
 * \brief Удаление
 * \param list Указатель на список, из которого нужно удалить значение
 * Вспомогательная функция, чтобы уменьшить main.
 * Общается с пользователем.
 */
void auxiliaryRemove(List* list)
{
    printf("Enter integer value:\n");
    int value;
    scanf("%d", &value);
    if (list->remove(value))
        printf("Value was been removed :)\n");
    else
        printf("Value was not found :(\n");
}

int main()
{
    ListTest test1(true);
    QTest::qExec(&test1);
    ListTest test2(false);
    QTest::qExec(&test2);
  /* В случае необходимости - раскомментировать.
    List* list = singleOrDouble();
    reminder();
    Select x = endOfProgram;
    int input;
    scanf("%d", &input);
    x = (Select) input;
    int k = 0;
    while (x != endOfProgram)
    {
        k++;
        switch (x)
        {
        case addNode:
        {
            auxiliaryAdd(list);
            break;
        }
        case removeNode:
        {
            auxiliaryRemove(list);
            break;
        }
        case lengthOfList:
        {
            printf("Length of list = %d  :)\n", list->length());
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
    delete list;
    return 0;
  */
}

