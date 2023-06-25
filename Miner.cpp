#include "Miner.h"
#include <assert.h>
Miner::Miner(int ID)
	:m_pCurrentState()
	,m_Location()
	,m_iGoldCarried()
	,m_iMoneyInBank()
	,m_iThurst()
	,m_iFatigue()
{
}

void Miner::Update()
{
}

void Miner::ChangeState(State* pNewState)
{
	// Make sure both states are valid before attempting to call their methods
	assert(m_pCurrentState && pNewState);

	// Call exit method
	m_pCurrentState->Exit(this);

	// Change state to new state
	m_pCurrentState = pNewState;

	// Call the entry method of the new state
	m_pCurrentState->Enter(this);
}

Vector2D Miner::GetLocation() const
{
	return m_Location;
}

void Miner::ChangeLocation(Vector2D& newLocation)
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
	m_iGoldCarried >= 10 ? true : false;
}

bool Miner::Thirsty()
{
	m_iThurst >= 100 ? true : false;
}


