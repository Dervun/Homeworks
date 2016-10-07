#pragma once
#include <cstdio>
#include "computer.h"

/*!
 * \brief Класс, описывающий локальную сеть, в которой гуляют вирусы.
 */
class LocalAreaNetwork
{
public:
    /*!
     * \brief Конструктор
     * \param informationFile Файл, в котором описана сеть
     * В файле описано количество компьютеров, их взаимосвязь и типы ОС.
     */
    LocalAreaNetwork(FILE* informationFile);
    /*!
     * \brief Просмотр состояния сети
     * Пишет в консоль по порядку в каждую строку - номер компьютера,
     * тип ОС компьютера и его состояние (заражён/чист).
     */
    void viewState();
    /*!
     * \brief Сделать шаг
     * За один шаг в локальной сети компьютеры, соединённые с заражёнными, заражаются с вероятностями,
     * соответствующими их типам ОС.
     */
    void makeStep();
    bool allComputersWasInfected();
    int getQuantityOfAllComputers()
    {
        return quantityOfComputers;
    }
    int getQuantityOfInfectedComputers();
    bool isInfected(int numberOfComputer)
    {
        return infected[numberOfComputer];
    }
    void setInfected(int numberOfComputer = 0, bool value = true);
    /*!
     * \param numberOfComputer номер компьютера, который надо попытаться заразить
     * Пытается заразить компьютер (результат рандомный).
     */
    virtual void tryToInfect(int numberOfComputer);
    virtual ~LocalAreaNetwork();
protected:
    int quantityOfComputers = 0;
    bool** matrixOfCommunications = nullptr;
    Computer** computers = nullptr; ///< Массив указателей на компьютеры локальной сети
    bool* infected = nullptr; ///< Массив заражённости компьютеров локальной сети
    void refreshInfected(); ///< Обновления данных в массиве
    void getTypes(FILE* informationFile); ///< Вспомогательная функция для конструктора
    void getCommunications(FILE* informationFile); ///< Вспомогательная функция для конструктора
};
