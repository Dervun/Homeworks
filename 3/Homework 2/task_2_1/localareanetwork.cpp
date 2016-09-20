#include "localareanetwork.h"
#include <cstdlib>


LocalAreaNetwork::LocalAreaNetwork(FILE *informationFile)
{
    char* firstString = new char[100];
    fgets(firstString, 100, informationFile);
    int quantity = atoi(firstString);
    delete []firstString;
    quantityOfComputers = quantity;


    computers = new Computer*[quantityOfComputers];
    matrixOfCommunications = new bool*[quantityOfComputers];
    for (int i = 0; i < quantityOfComputers; i++)
        matrixOfCommunications[i] = new bool[quantityOfComputers];
    for (int i = 0; i < quantityOfComputers; i++)
        for (int j = 0; j < quantityOfComputers; j++)
            matrixOfCommunications[i][j] = false;
    const unsigned int lengthOfString = quantityOfComputers * 3;  //With the stock


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


    char* currentString = new char[lengthOfString];
    for (int i = 0; i < quantityOfComputers; i++)
    {
        fgets(currentString, lengthOfString, informationFile);
        numberOfSymbol = 0;
        for  (int j = 0; j < quantityOfComputers; j++)
        {
            if (currentString[numberOfSymbol] == '1')
                matrixOfCommunications[i][j] = true;
            else
                matrixOfCommunications[i][j] = false;
            numberOfSymbol += 2;
        }
    }
    delete currentString;
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
    printf("An attempt to make a step :)\n");
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
