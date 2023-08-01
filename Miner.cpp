#include "Miner.h"
#include "MinerOwnedStates.h"
#include <assert.h>

Miner::Miner(int id)
	:m_Location(shack),
	m_iGoldCarried(0),
	m_iMoneyInBank(0),
	m_iThurst(0),
	m_iFatigue(0),
	m_iMoneyEarntToday(0),
	BaseGameEntity(id)
{
	m_pStateMachine = new StateMachine<Miner>(this);

	m_pStateMachine->SetCurrentState(GoHomeAndSleepTillRested::Instance());
	m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
}

Miner::~Miner()
{
	m_pStateMachine = nullptr;
	delete m_pStateMachine;
}

void Miner::Update()
{
	m_iThurst += 1;

	m_pStateMachine->Update();
}

StateMachine<Miner>* Miner::GetFSM() const
{
	return m_pStateMachine;
}

void Miner::AddToMoneyEarntToday(int addToMoneyEarntToday)
{
	m_iMoneyEarntToday += addToMoneyEarntToday;
}

void Miner::SetToMoneyEarntToday(int moneyEarntToday)
{
	m_iMoneyEarntToday += moneyEarntToday;
}

int Miner::GetMoneyEarntToday() const
{
	return m_iMoneyEarntToday;
}

location_type Miner::GetLocation() const
{
	return m_Location;
}

void Miner::ChangeLocation(location_type newLocation)
{
	m_Location = newLocation;
}

void Miner::AddToGoldCarried(int iAddToGold)
{
	m_iGoldCarried += iAddToGold;
}

void Miner::IncreaseFatigue()
{
	m_iFatigue += 20;
}

bool Miner::PocketsFull()
{
	// If gold carried is value then pockets are full
	if(m_iGoldCarried >= 3) 
		return true;
	return false;
}

bool Miner::Thirsty()
{
	if(m_iThurst <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Miner::DepositGoldInBank(int amountOfGoldToDeposit)
{
	m_iMoneyInBank += amountOfGoldToDeposit;
}

void Miner::SetGoldCarried(int goldCarried)
{
	m_iGoldCarried = goldCarried;
}

int Miner::GetGoldCarried() const
{
	return m_iGoldCarried;
}

int Miner::GetMoneyInBank() const
{
	return m_iMoneyInBank;
}

void Miner::RestUp()
{
	m_iFatigue -= 20;
}

bool Miner::IsRested()
{
	if(m_iFatigue <= 0)
		return true;
	return false;
}

void Miner::QuenchThirst()
{
	m_iGoldCarried -= 2;
	m_iThurst = 100;
	// Need a check to see if Miner has enough funds -----------
}

void Miner::IncreaseThirst()
{
	m_iThurst += 20;
}


