#ifndef MINER_H
#define MINER_H

#include "State.h"
#include "Vector.h"
class Miner : public BaseGameEntity
{
public:
	Miner(int ID);

	virtual void Update() override;

	void ChangeState(State* pNewState);

	Vector2D GetLocation() const;

	void ChangeLocation(Vector2D& vector);

	void AddToGoldCarried(int iaddToGold);
	void IncreaseFatigue();

	bool PocketsFull();
	bool Thirsty();
private:
	
	// A pointer to an instance of the State
	State* m_pCurrentState;
	
	// Place where miner is currently situated
	Vector2D m_Location;

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
