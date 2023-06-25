#ifndef GOHOMEANDSLEEPTILLRESTEDSTATE_H
#define GOHOMEANDSLEEPTILLRESTEDSTATE_H

#include "State.h"

class GoHomeAndSleepTillRested : public State
{
public:

	// Singleton
	static GoHomeAndSleepTillRested* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	GoHomeAndSleepTillRested();
};
#endif // !GOHOMEANDSLEEPTILLRESTEDSTATE_H

