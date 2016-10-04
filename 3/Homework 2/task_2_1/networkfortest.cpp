#include "networkfortest.h"

void NetworkForTest::tryToInfect(int numberOfComputer)
{
    computers[numberOfComputer]->setInfected(true);
}
