#include "networkfortest.h"


void NetworkForTest::makeStep()
{
    for (int i = 0; i < quantityOfComputers; i++)
    {
        if (infected[i])
        {
            for (int j = 0; j < quantityOfComputers; j++)
            {
                if (matrixOfCommunications[i][j] && !computers[j]->isInfected())
                    computers[j]->setInfected(true);
            }
        }
    }

    refreshInfected();
}
