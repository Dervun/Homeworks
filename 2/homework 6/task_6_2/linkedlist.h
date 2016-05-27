#pragma once
#include <stdexcept>

/*!
 * \brief Двусвязный список
 */
class LinkedList
{
public:
    class RemoveNotExistsElementExeption : public std::exception
    {
    public:
        const char* details() const noexcept
        {
            return "Error! Element does not exists!";
        }
    };
    /*!
     * \brief Создание двусвязного списка
     */
    LinkedList();
    /*!
     * \brief Деструктор
     * Удаляет все ячейки, которые были в списке.
     */
    ~LinkedList();
    /*!
     * \brief Добавление
     * \param x Значение, которое надо добавить
     * Функция добавляет ячейку с заданным значением в голову списка.
     */
    void add(int x);
    /*!
     * \brief Удаление
     * \param x Значение, ячейку с которым надо удалить.
     * Из-за того, что в списке могут храниться несколько ячеек с одним и тем же значением, возникает неоднозначность удаления.
     * Я удаляю ближайший к голове элемент.
     */
    void remove(int x) throw (RemoveNotExistsElementExeption);
    /*!
     * \brief Существование
     * \param x Значение, которое ф-я проверяет на принадлежность к списку.
     * \return true - если элемент x есть в списке, иначе - false.
     */
    bool exists(int x);
    /*!
     * \brief Длина списка
     * \return Целое число - длину списка, не считая охранника.
     */
    int length()
    {
        return listLength;
    }
    /*!
     * \brief Получить клона
     * \return Указатель на идентичный список.
     * Функция создаёт такой же список и возвращает указатель на созданную копию.
     */
    LinkedList* getClone();
private:
    /*!
     * \brief Ячейка  двусвязного списка
     */
    class ListNode
    {
    public:
        ListNode* next = nullptr; ///< Указатель на следующий элемент.
        ListNode* previous = nullptr; ///< Указатель на предыдущий элемент.
        int value = 0; ///< Значение, хранящееся в ячейке списка.
    };
    ListNode* first; ///< Указатель на первый элемент списка.
    int listLength = 0; ///< Текущая длина списка.
};
