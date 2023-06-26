#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <assert.h>

template<class entity_type>
class StateMachine 
{
public:
	StateMachine(entity_type* owner): m_pOwner(owner),
									  m_pCurrentState(nullptr),
									  m_pPreviousState(nullptr),
									  m_pGlobalState(nullptr)
	{}

	// Initialize FSM
	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }

	// Update FSM
	void Update() const
	{
		if(m_pGlobalState)	
			m_pGlobalState->Execute(m_pOwner);

		if(m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

	// Change to new state
	void ChangeState(State<entity_type>* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState> trying to change to null state");

		// Keep a record of previous state
		m_pPreviousState = m_pCurrentState;

		// Call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);

		// Change state to the new state
		m_pCurrentState = pNewState;

		// Call entry method of new state
		m_pCurrentState->Enter(m_pOwner);
	}

	// Change back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	// Accessors
	State<entity_type>* CurrentState() const { return m_pCurrentState; }
	State<entity_type>* PreviousState() const { return m_pPreviousState; }
	State<entity_type>* GlobalState() const { return m_pGlobalState; }

	// Returns true if current state's type is equal to the type of the class
	bool IsInState(const State<entity_type>& st) const; // FIX THIS ----------
	


private:

	// Pointer to the agent that owns this instance
	entity_type* m_pOwner;

	State<entity_type>* m_pCurrentState;
	State<entity_type>* m_pPreviousState; // Record of the last state
	State<entity_type>* m_pGlobalState; // This state logic is called everytime the FSM is updated

};
#endif // !STATEMACHINE_H

