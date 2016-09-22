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
    ~LocalAreaNetwork();
private:
    int quantityOfComputers = 0;
    bool** matrixOfCommunications = nullptr;
    Computer** computers = nullptr;
};
