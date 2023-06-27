#ifndef MINER_H
#define MINER_H

#include "Vector.h"
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"

class Miner : public BaseGameEntity
{
public:
	Miner(int id);

	~Miner();

	virtual void Update() override;

	location_type GetLocation() const;

	void ChangeLocation(location_type vector);

	void AddToGoldCarried(int addToGold);
	void IncreaseFatigue();

	bool PocketsFull();
	bool Thirsty();

	// Deposit gold in bank
	void DepositGoldInBank(int amountOfGoldToDeposit);

	void SetGoldCarried(int goldCarried);
	int GetGoldCarried() const;

	int GetMoneyInBank() const;

	void RestUp();

	bool IsRested();

	void QuenchThirst();
	
	StateMachine<Miner>* GetFSM() const;


private:
	
	// Instance of the state machine class
	StateMachine<Miner>* m_pStateMachine;

	// Place where miner is currently situated
	location_type m_Location;

	// How many nuggets the miner has carried in his pocket
	int m_iGoldCarried;

	// How much money the miner has deposited in the bank
	int m_iMoneyInBank;

	// The higher the value, the thirstier the miner
	int m_iThurst;

	// The higher the value, the more tired the miner
	int m_iFatigue;

};


#endif // !MINER_H
