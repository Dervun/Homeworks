#pragma once

/*!
 * \brief Абстрактный класс "выводилка"
 */
class Writer
{
public:
    /*!
     * \brief Функция вывода массива
     * \param array Массив, который надо вывести
     * \param size Размер данного массива
     */
    void write(int** array, int size);
    /*!
     * \brief Пустой виртуальный деструктор
     * Без этой строчки программа не компилируется.
     */
    virtual ~Writer(){}
protected:
    /*!
     * \brief Прототип функции печати
     * \param value Значение для печати
     */
    virtual void print(int value) = 0;
};
