#include "computer.h"
#include <ctime>
#include <cstdlib>

Computer::Computer(TypeOfOS value)
{
    type = value;
    switch (type)
    {
    case Linux:
    {
        probabitityOfInfection = 0.5;
        break;
    }
    case Windows:
    {
        probabitityOfInfection = 0.7;
        break;
    }
    case Mac:
    {
        probabitityOfInfection = 0.3;
        break;
    }
    default:
        break;
    }
}

bool Computer::tryToInfect()
{
    srand(time(0));
    double currentProbability = (double) rand() / RAND_MAX;
    if (currentProbability < probabitityOfInfection)
        infected = true;
    return infected;
}
