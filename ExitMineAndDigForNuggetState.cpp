#include "ExitMineAndDigForNuggetState.h"
#include <iostream>
#include "VisitBankAndDepositGoldState.h"
#include "QuenchThirstState.h"
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget instance;

    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
    Vector2D goldmine; // Temp variable for goldmine location - move into header

    // If mine is not locatied at the mine, go to mine
    if(pMiner->GetLocation() != goldmine)
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "Walkin' to the gold mine";

        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
    // Digs under he is carrying max amount of nuggets
    // If thirsty, stop digging
    // Changes state to go to saloon

    pMiner->AddToGoldCarried(1);
    pMiner->IncreaseFatigue();

    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Pickin' up a nugget";

    // If enough gold is mined, go and put it in the bank
    if(pMiner->PocketsFull())
    {
        pMiner->ChangeState(VisitBankAndDepositGold::Instance()); 
    }

    // If thirsty get a whiskey
    if(pMiner->Thirsty())
    {
        pMiner->ChangeState(QuenchThirst::Instance()); 
    }
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Ah'm leavin' the gold mine with mah pockets full o' sweet gold";
}


