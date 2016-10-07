#pragma once
#include "localareanetwork.h"

/*!
 * \brief Вспомогательный класс локальной сети
 * Класс нужен, чтобы поменять поведение заражения компьютеров и сделать его гарантированным.
 * С помощью этого можно будет отслеживать последовательность заражаемых компьютеров.
 */
class NetworkForTest : public LocalAreaNetwork
{
public:
    /*!
     * Создаётся так же, как локальная сеть
     */
    NetworkForTest(FILE* informationFile) : LocalAreaNetwork(informationFile){}
    /*!
     * \param numberOfComputer номер заражаемого компьютера
     * Заражает компьютер гарантированно!
     */
    void tryToInfect(int numberOfComputer);
};
