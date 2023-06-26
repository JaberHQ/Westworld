#ifndef STATE_H
#define STATE_H

#include <iostream>

class Miner;

template <class entity_type>
class State
{
public:

	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;

	~State(){}

};



#endif // !STATE_H


