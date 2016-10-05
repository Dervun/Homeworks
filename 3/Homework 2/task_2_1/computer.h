#pragma once

enum TypeOfOS
{
    Linux,
    Windows,
    Mac
};

/*!
 * \brief сласс Computer
 * Класс описывает компьютер, который может заражаться.
 */
class Computer
{
public:
    /*!
     * \brief Конструктор
     * \param value Тип операционной системы создаваемого компьютера
     * От типа ОС зависит вероятность заражения.
     */
    Computer(TypeOfOS value = Linux);
    TypeOfOS getType()
    {
        return type;
    }
    void setInfected(bool value = true)
    {
        infected = value;
    }
    /*!
     * \brief Проверка на наличие заражения
     * \return true - заражён, false - не заражён.
     */
    bool isInfected()
    {
        return infected;
    }
    /*!
     * \brief Попытаться заразить компьютер
     * \return true - успешно (компьютер заражён), false - неудача (компьютер не был заражён).
     */
    bool tryToInfect();
    double getProbabitityOfInfection()
    {
        return probabitityOfInfection;
    }

private:
    bool infected = false; ///< Текущее состояние (заражён/не заражён)
    double probabitityOfInfection = 0.5;
    TypeOfOS type = Linux;
};
