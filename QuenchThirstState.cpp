#include "QuenchThirstState.h"

QuenchThirst* QuenchThirst::Instance()
{
    static QuenchThirst instance;

    return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
}

void QuenchThirst::Execute(Miner* pMiner)
{
}

void QuenchThirst::Exit(Miner* pMiner)
{
}
