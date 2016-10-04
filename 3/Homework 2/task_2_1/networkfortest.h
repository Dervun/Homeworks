#pragma once
#include "localareanetwork.h"

class NetworkForTest : public LocalAreaNetwork
{
public:
    NetworkForTest(FILE* informationFile) : LocalAreaNetwork(informationFile){}
    void makeStep();
};
