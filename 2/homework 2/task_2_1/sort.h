#pragma once
template <typename T>

/*!
 * \brief Виртуальный класс сортировки
 * От него будут наследоваться разные сортировки, там же будет и реализация.
 */
class Sort
{
public:
    /*!
     * \brief Сортировка
     * \param array Массив, который надо сортировать
     * \param size Размер данного массива
     */
    virtual void sort(T* array, int size) = 0;
    /*!
     * \brief Деструктор
     * Пустой виртуальный деструктор, потому что без этой строчки программа не компилируется.
     */
    virtual ~Sort(){}
};