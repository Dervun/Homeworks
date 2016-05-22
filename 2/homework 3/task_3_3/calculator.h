#pragma once
#include "linkedstack.h"

/*!
 * \brief Калькулятор
 * Считает значение выражения, записанного в строчку.
 * \warning Класс LinkedStack<template T> бросает исключения типа LinkedStack<T>::EmptyStackExeption в случае
 * ввода некорректного выражения.
 */
class Calculator
{
public:
    /*!
     * \brief Счёт
     * \param inputExpression Исходное выражение
     * \return Посчитанное значение с плавающей точкой.
     */
    static double calculate(char *inputExpression);
private:
    /*!
     * \brief Танслятор
     * \param expression Математическое выражение в инфиксной форме записи.
     * \return Математическое выражение в постфиксной форме записи.
     */
    static char *infixToPostfix(char *expression);
};
