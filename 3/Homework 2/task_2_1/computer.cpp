#include <ctime>
#include <cstdlib>

#include "computer.h"

Computer::Computer(TypeOfOS value)
{
    type = value;
    switch (type)
    {
    case Linux:
    {
        probabitityOfInfection = 0.4;
        break;
    }
    case Windows:
    {
        probabitityOfInfection = 0.6;
        break;
    }
    case Mac:
    {
        probabitityOfInfection = 0.25;
        break;
    }
    default:
        break;
    }
    srand(time(0));
}

bool Computer::tryToInfect()
{
    if (infected)
        return true;
    double currentProbability = (double) rand() / RAND_MAX;
    if (currentProbability < probabitityOfInfection)
        infected = true;
    return infected;
}
