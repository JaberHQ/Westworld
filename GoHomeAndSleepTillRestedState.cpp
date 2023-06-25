#include "GoHomeAndSleepTillRestedState.h"

GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
    static GoHomeAndSleepTillRested instance;

    return &instance;
}

void GoHomeAndSleepTillRested::Enter(Miner* pMiner)
{
}

void GoHomeAndSleepTillRested::Execute(Miner* pMiner)
{
}

void GoHomeAndSleepTillRested::Exit(Miner* pMiner)
{
}
