#ifndef ENTERMINEANDDIGFORNUGGETSTATE_H
#define ENTERMINEANDDIGFORNUGGETSTATE_H

#include "State.h"
#include "Miner.h"
class EnterMineAndDigForNugget : public State
{

public:
	// Singleton
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	EnterMineAndDigForNugget();
};
#endif // !ENTERMINEANDDIGFORNUGGETSTATE_H