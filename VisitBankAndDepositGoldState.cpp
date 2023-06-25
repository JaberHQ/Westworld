#include "VisitBankAndDepositGoldState.h"

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
    static VisitBankAndDepositGold instance;

    return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
}

void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
}

