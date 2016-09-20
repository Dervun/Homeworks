#pragma once

enum TypeOfOS
{
    Linux,
    Windows,
    Mac
};

class Computer
{
public:
    Computer(TypeOfOS value);
    TypeOfOS getType()
    {
        return type;
    }
    void setInfected(bool value)
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

private:
    bool infected = false;
    double probabitityOfInfection = 0.5;
    TypeOfOS type = Linux;
};
