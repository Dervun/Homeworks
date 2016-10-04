#pragma once
#include <cstdio>
#include "computer.h"

class LocalAreaNetwork
{
public:
    LocalAreaNetwork(FILE* informationFile);
    void viewState();
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
    void setInfected(int numberOfComputer, bool value);
    virtual void tryToInfect(int numberOfComputer);
    virtual ~LocalAreaNetwork();
protected:
    int quantityOfComputers = 0;
    bool** matrixOfCommunications = nullptr;
    Computer** computers = nullptr;
    bool* infected = nullptr;
    void refreshInfected();
    void getTypes(FILE* informationFile);
    void getCommunications(FILE* informationFile);
};
