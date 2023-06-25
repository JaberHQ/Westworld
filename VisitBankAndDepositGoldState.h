#ifndef VISITBANKANDDEPOSITGOLDSTATE_H
#define VISITBANKANDDEPOSITGOLDSTATE_H

#include "State.h"

class VisitBankAndDepositGold : public State
{
public:
	// Singleton
	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	VisitBankAndDepositGold();
};

#endif // !VISITBANKANDDEPOSITGOLDSTATE_H

