#ifndef STATE_H
#define STATE_H

#include "BaseGameEntity.h"
#include "Miner.h"
#include <iostream>

class State
{
public:

	~State();

	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;

	std::string GetNameOfEntity(int ID);

};



#endif // !STATE_H

