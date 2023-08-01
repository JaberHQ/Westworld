#include "MinerOwnedStates.h"
#include "Vector.h"
#include "Miner.h"
#include "EntityNames.h"
#include "Locations.h"

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget instance;

    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{

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
    pMiner->IncreaseThirst();

    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Pickin' up a nugget";

    // If enough gold is mined, go and put it in the bank
    if(pMiner->PocketsFull())
    {
        pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
    }


    // If thirsty get a whiskey
    if(pMiner->Thirsty())
    {
        pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Ah'm leavin' the gold mine with mah pockets full o' sweet gold";
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
    static VisitBankAndDepositGold instance;

    return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
    // If mine is not locatied at the mine, go to mine
    if (pMiner->GetLocation() != bank)
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "Goin' to the bank. Yes siree";

        pMiner->ChangeLocation(bank);
    }
}

void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
    pMiner->DepositGoldInBank(pMiner->GetGoldCarried());

    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Depositin' gold. Total savings now: " << pMiner->GetMoneyInBank();

    enoughGoldToGoHome += pMiner->GetGoldCarried();
    pMiner->SetGoldCarried(0);
    if(enoughGoldToGoHome >= 5)
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "Woohoo! Rich enough for now. Back home to mah li'l lady";

        enoughGoldToGoHome = 0;
        pMiner->GetFSM()->ChangeState(GoHomeAndSleepTillRested::Instance());
    }
    else
    {
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }

}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Leavin' the bank";
}

GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
    static GoHomeAndSleepTillRested instance;

    return&instance;
}

void GoHomeAndSleepTillRested::Enter(Miner* pMiner)
{
    // If mine is not locatied at the mine, go to mine
    if (pMiner->GetLocation() != shack)
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "Walkin' home";

        pMiner->ChangeLocation(shack);
    }
}

void GoHomeAndSleepTillRested::Execute(Miner* pMiner)
{
    pMiner->RestUp();

    

    if(pMiner->IsRested())
    {
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
    else
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "ZZZZ...";
    }
}

void GoHomeAndSleepTillRested::Exit(Miner* pMiner)
{
    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "What a darn fantastic nap! Time to find more gold";
}

QuenchThirst* QuenchThirst::Instance()
{
    static QuenchThirst instance;

    return&instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
    // If mine is not locatied at the mine, go to mine
    if (pMiner->GetLocation() != saloon)
    {
        std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
            << "Boy, ah sure is thusty! Walkin' to the saloon";

        pMiner->ChangeLocation(saloon);
    }
}

void QuenchThirst::Execute(Miner* pMiner)
{
    pMiner->QuenchThirst();

    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "That's mighty fine sippin liquor";

    if(!pMiner->Thirsty())
    {
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void QuenchThirst::Exit(Miner* pMiner)
{
    std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "Leavin' the saloon, feelin' good";
}

MinerGlobalState* MinerGlobalState::Instance()
{
    static MinerGlobalState instance;

    return&instance;
}

void MinerGlobalState::Enter(Miner* pMiner)
{
}

void MinerGlobalState::Execute(Miner* pMiner)
{
}

void MinerGlobalState::Exit(Miner* pMiner)
{
    pMiner->GetFSM()->RevertToPreviousState();
}