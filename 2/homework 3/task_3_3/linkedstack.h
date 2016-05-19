#pragma once
#include <cstdio>


template <typename T>
/*!
 * \brief Стек на указателях.
 * Шаблонный класс
 * \warning Функции T pop() и T top() бросают исключения типа LinkedStack<T>::EmptyStackExeption в случае попытки взять или посмотреть соответственно последний элемент стека, если такового не обнаружено.
 */
class LinkedStack
{
public:
    /*!
     * \brief Класс для исключения в случае пустого стека.
     */
    class EmptyStackExeption
    {
    public:
        EmptyStackExeption(char *newMessage)
        {
            massage = newMessage;
        }
    private:
        char* massage;
    };
    LinkedStack(){}
    ~LinkedStack();
    bool push(T newValue);
    T pop();
    T top();
    bool isEmpty()
    {
        return !last;
    }
private:
    class StackNode
    {
    public:
        StackNode(T newValue)
        {
            value = newValue;
        }
        ~StackNode(){}
        T value;
        StackNode* next = nullptr;
    };
    StackNode* last = nullptr;
};

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (last)
    {
        StackNode* temporaryNode = last;
        last = last->next;
        delete temporaryNode;
    }
}

template <typename T>
bool LinkedStack<T>::push(T newValue)
{
    StackNode* newNode = new StackNode(newValue);
    newNode->next = last;
    last = newNode;
    return true;
}

template <typename T>
T LinkedStack<T>::pop()
{
    if (isEmpty())
    {
        throw EmptyStackExeption("Trying take an element from the empty stack.");
        return 0;
    }
    T valueToReturn = last->value;
    StackNode* temporaryNode = last;
    last = last->next;
    delete temporaryNode;
    return valueToReturn;
}

template <typename T>
T LinkedStack<T>::top()
{
    if (isEmpty())
    {
        throw EmptyStackExeption("Trying show an element from the empty stack.");
        return 0;
    }
    return last->value;
}
