#ifndef QUENCHTHIRSTSTATE_H
#define QUENCHTHIRSTSTATE_H

#include "State.h"

class QuenchThirst : public State
{
public:

	// Singleton
	static QuenchThirst* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	QuenchThirst();
};

#endif // !QUENCHTHIRSTSTATE_H
