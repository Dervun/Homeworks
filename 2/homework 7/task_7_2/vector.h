#pragma once
#include <QList>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T, int n>
/*!
 * \brief Шаблонный класс, представляющий n-мерный вектор.
 */
class Vector
{
public:
    /*!
     * \brief Класс-исключение
     * Выход за пределы вектора.
     */
    class GoingBeyondVector : public std::exception
    {
    public:
        const char* details() const noexcept
        {
            return "Error! Attempt to going beyond vector!";
        }
    };
    /*!
     * \brief Пустой конструктор
     * Создаёт нулевой вектор.
     */
    Vector() {}
    /*!
     * \brief Конструктор вектора по заданным координатам
     * \param coordinates Координаты
     */
    Vector(QList<int> &coordinates);
    /*!
     * \brief Конструктор копирования
     * \param vect Вектор, который надо скопировать.
     */
    Vector(const Vector<T, n> &vect);
    /*!
     * \brief На i-м месте
     * \param i Номер координаты.
     * \return Значение i-й координаты вектора.
     */
    T at(const int i) const throw(GoingBeyondVector);
    /*!
     * \brief operator +
     * \return Сумма векторов.
     */
    Vector operator + (const Vector<T, n> &vector);
    /*!
     * \brief operator -
     * \return Разность векторов.
     */
    Vector operator - (const Vector<T, n> &vector);
    /*!
     * \brief operator ==
     * \return  true - если вектора равны, иначе - false.
     */
    bool operator == (const Vector<T, n> &vector);
    /*!
     * \brief operator *
     * \param vector
     * \return Результат скалярного умножения
     * Оператор скалярного умножения.
     */
    T operator *(const Vector<T, n> &vector);
    /*!
     * \brief Оператор []
     * \param i Номер координаты.
     * \return Ссылку на i-ю координату.
     */
    T &operator [] (const int i) throw(GoingBeyondVector);
    /*!
     * \brief Пустота вектора
     * \return true - пустой, false - не пустой.
     */
    bool isNull();

private:
    T vector[n] = {}; ///< Сам вектор.
};


template <typename T, int n>
Vector<T, n>::Vector(QList<int> &coordinates)
{
    int length = min(n, coordinates.size());
    for (int i = 0; i < length; i++)
        vector[i] = coordinates.at(i);
}

template <typename T, int n>
Vector<T, n>::Vector(const Vector<T, n> &vect)
{
    for (int i = 0; i < n; i++)
        vector[i] = vect.at(i);
}

template <typename T, int n>
T Vector<T, n>::at(const int i) const throw(GoingBeyondVector)
{
    if (i < 0 || i > n - 1)
        throw GoingBeyondVector();
    return vector[i];
}

template <typename T, int n>
Vector<T, n> Vector<T, n>::operator + (const Vector<T, n> &vector)
{
    QList<T> coordinates;
    for (int i = 0; i < n; i++)
        coordinates.append(this->at(i) + vector.at(i)); // Переделать при возможности в this[i] + vector[i]
    return Vector<T, n>(coordinates);
}

template <typename T, int n>
Vector<T, n> Vector<T, n>::operator - (const Vector<T, n> &vector)
{
    QList<T> coordinates;
    for (int i = 0; i < n; i++)
        coordinates.append(this->at(i) - vector.at(i)); // Переделать при возможности в this[i] - vector[i]
    return Vector<T, n>(coordinates);
}

template <typename T, int n>
bool Vector<T, n>::operator == (const Vector<T, n> &vector)
{
    for (int i = 0; i < n; i++)
        if (this->at(i) != vector.at(i))
            return false;
    return true;
}

template <typename T, int n>
T Vector<T, n>::operator * (const Vector<T, n> &vector)
{
    T result = 0;
    for (int i = 0; i < n; i++)
        result += this->at(i) * vector.at(i);
    return result;
}

template <typename T, int n>
T &Vector<T, n>::operator [] (const int i) throw(GoingBeyondVector)
{
    if (i < 0 || i >= n)
            throw GoingBeyondVector();
    return vector[i];
}

template <typename T, int n>
bool Vector<T, n>::isNull()
{
    for (int i = 0; i < n; i++)
        if (this->at(i) != 0)
            return false;
    return true;
}


