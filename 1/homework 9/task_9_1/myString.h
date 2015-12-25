/*!
 * Реализация строки (типа не массив символов, а элемент)
 * \brief Строка
 */
#pragma once
#include <cstddef>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

/// \brief Структура, описывающая строку (String)
/*!
 * Структура, состоящая из указателя на массив символов и длины этого массива
 * \param string Массив символов
 * \param length Длина строки (без нуль-терминатора)
*/
struct String{
    char *string;
    int length;
};

/// Набор возможных исходов сравнения 2-х объектов
enum Comparison{
    equivalent = 0, ///< Указывает, что объекты равны
    bigger, ///< Указывает, что первый объект больше второго
    smaller ///< Указывает, что первый объект меньше второго
};
/*!
 * \brief Создаёт пустую строку
 * \return Указатель на созданную строку
 */
String *createString();
/*!
 * Создаёт объект типа String, в который помещает входной массив char
 * \brief Создаёт String
 * \param buffer Указатель на массив символов (строку)
 * \return указатель на объект типа String
 */
String *createGivenString(char *buffer);
/*!
 * Дописывает в имеющуюся строку ту строку (String), которую получила на вход
 * \brief Конкатенация строк
 * \param s Указатель на имеющуюся строку (String)
 * \param buffer Указатель на строку (char*), которую надо приписать к имеющейся
 * \return Указатель на итоговую строку (String)
 */
void addToString(String *s, char *buffer);
/*!
 * Освобождает память, выделенную под строку (String).
 * \brief Удаляет строку
 * \param s Указатель на строку (String), которую надо удалить
 */
void removeString(String *s);
/*!
 * Функция сравнивает 2 строки (в лексикографическом порядке).
 * \brief Сравнивает строки
 * \param s1 Первая строка
 * \param s2 Вторая строка
 * \return Значение типа Comparison - bigger, smaller или equivalent.
 * По сути, функция возвращает "первое слово идёт после второго в словаре", "первое слово идёт перед вторым в словаре"
 * или "слова одинаковые".
 */
Comparison compareString(String *s1, String *s2);
/*!
 * Функция принимает строку String, выделяет динамически память, в которую кладёт строку *char
 * и возвращает указатель на созданную строку (*char).
 * \brief Преобразование String к char*
 * \param s Указатель на строку (String)
 * \return Указатель на созданную строку типа *char
 */
char *stringToChar(String *s);
