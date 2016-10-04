#include "localareanetwork.h"
#include <cstdlib>

int getQuantity(FILE* informationFile)
{
    char* firstString = new char[100];
    fgets(firstString, 100, informationFile);
    int quantity = atoi(firstString);
    delete []firstString;
    return quantity;
}

LocalAreaNetwork::LocalAreaNetwork(FILE *informationFile)
{
    quantityOfComputers = getQuantity(informationFile);
    computers = new Computer*[quantityOfComputers];
    infected = new bool[quantityOfComputers];
    getTypes(informationFile);
    computers[0]->setInfected(true);
    refreshInfected();
    getCommunications(informationFile);
}

void LocalAreaNetwork::viewState()
{
    printf("Current state:\n");
    for (int i = 0; i < quantityOfComputers; i++)
    {
        printf("%d)OS - ", i);
        TypeOfOS currentType = computers[i]->getType();
        if (currentType == Linux)
            printf("Linux");
        else if (currentType == Windows)
            printf("Windows");
        else
            printf("Mac");
        if (computers[i]->isInfected())
            printf(", Infected!");
        else
            printf(", Clear :)");
        printf("\n");
    }
}

void LocalAreaNetwork::makeStep()
{
    for (int i = 0; i < quantityOfComputers; i++)
    {
        if (infected[i])
        {
            for (int j = 0; j < quantityOfComputers; j++)
            {
                if (matrixOfCommunications[i][j] && !computers[j]->isInfected())
                    computers[j]->tryToInfect();
            }
        }
    }

    refreshInfected();
}

bool LocalAreaNetwork::allComputersWasInfected()
{
    for (int i = 0; i < quantityOfComputers; i++)
    {
        if (!infected[i])
            return false;
    }
    return true;
}

int LocalAreaNetwork::getQuantityOfInfectedComputers()
{
    int result = 0;
    for (int i = 0; i < quantityOfComputers; i++)
    {
        if (infected[i])
            result++;
    }
    return result;
}

LocalAreaNetwork::~LocalAreaNetwork()
{
    for (int i = 0; i < quantityOfComputers; i++)
        delete computers[i];
    delete []computers;
    for (int i = 0; i < quantityOfComputers; i++)
        delete []matrixOfCommunications[i];
    delete []matrixOfCommunications;
}

void LocalAreaNetwork::refreshInfected()
{
    for (int i = 0; i < quantityOfComputers; i++)
        infected[i] = computers[i]->isInfected();
}

void LocalAreaNetwork::getTypes(FILE *informationFile)
{
    const unsigned int lengthOfString = quantityOfComputers * 3;
    char* types = new char[lengthOfString];
    fgets(types, lengthOfString, informationFile);
    int numberOfSymbol = 0;
    Computer* currentComputer = nullptr;
    for (int i = 0; i < quantityOfComputers; i++)
    {
        if (types[numberOfSymbol] == 'L')
            currentComputer = new Computer(Linux);
        else if (types[numberOfSymbol] == 'W')
            currentComputer = new Computer(Windows);
        else
            currentComputer = new Computer(Mac);
        computers[i] = currentComputer;
        numberOfSymbol += 2;
    }
    delete types;
}

void LocalAreaNetwork::getCommunications(FILE* informationFile)
{
    matrixOfCommunications = new bool*[quantityOfComputers];
    for (int i = 0; i < quantityOfComputers; i++)
        matrixOfCommunications[i] = new bool[quantityOfComputers];
    for (int i = 0; i < quantityOfComputers; i++)
        for (int j = 0; j < quantityOfComputers; j++)
            matrixOfCommunications[i][j] = false;
    const unsigned int lengthOfString = quantityOfComputers * 3;
    char* currentString = new char[lengthOfString];
    for (int i = 0; i < quantityOfComputers; i++)
    {
        fgets(currentString, lengthOfString, informationFile);
        int numberOfSymbol = 0;
        for  (int j = 0; j < quantityOfComputers; j++)
        {
            if (currentString[numberOfSymbol] == '1')
                matrixOfCommunications[i][j] = true;
            numberOfSymbol += 2;
        }
    }
    delete []currentString;
}
