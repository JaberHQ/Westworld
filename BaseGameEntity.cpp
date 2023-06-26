#include "BaseGameEntity.h"

BaseGameEntity::BaseGameEntity(int id)
	:m_ID()
{
	SetID(id);
}

BaseGameEntity::~BaseGameEntity()
{
}

int BaseGameEntity::ID() const
{
	return m_ID;
}

void BaseGameEntity::SetID(int val)
{
}

