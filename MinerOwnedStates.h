#ifndef MINEROWNEDSTATES_H
#define MINEROWNEDSTATES_H

#include "State.h"
class EnterMineAndDigForNugget : public State<Miner>
{
public:
	// Singleton
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	EnterMineAndDigForNugget() {}

	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);

	EnterMineAndDigForNugget& operator= (const EnterMineAndDigForNugget&);
};


class VisitBankAndDepositGold : public State<Miner>
{
public:
	// Singleton
	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	VisitBankAndDepositGold() {}

	VisitBankAndDepositGold(const VisitBankAndDepositGold&);

	VisitBankAndDepositGold& operator= (const VisitBankAndDepositGold&);

private:
	int enoughGoldToGoHome = 0; 


};


class GoHomeAndSleepTillRested : public State<Miner>
{
public:

	// Singleton
	static GoHomeAndSleepTillRested* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	GoHomeAndSleepTillRested() {}

	GoHomeAndSleepTillRested(const GoHomeAndSleepTillRested&);

	GoHomeAndSleepTillRested& operator= (const GoHomeAndSleepTillRested&);

};



class QuenchThirst : public State<Miner>
{
public:

	// Singleton
	static QuenchThirst* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	QuenchThirst() {}

	QuenchThirst(const QuenchThirst&);

	QuenchThirst& operator= (const QuenchThirst&);

};


class MinerGlobalState : public State<Miner>
{
public:
	// Singleton
	static MinerGlobalState* Instance();

	virtual void Enter(Miner* pMiner) override;
	virtual void Execute(Miner* pMiner) override;
	virtual void Exit(Miner* pMiner) override;

private:
	MinerGlobalState() {}

	MinerGlobalState(const MinerGlobalState&);

	MinerGlobalState& operator= (const MinerGlobalState&);
};

#endif // !MINEROWNEDSTATES_H

