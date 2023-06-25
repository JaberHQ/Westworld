#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

class BaseGameEntity
{
public:
	BaseGameEntity();
	BaseGameEntity(int id);
	~BaseGameEntity();

	virtual void Update() = 0;

	int ID() const;

private:
	// Every entity has a unique identifying number
	int m_ID;

	// After each entity is instantiated, this value is updated
	static int m_iNextValidID; // Static inside a class means that ID will share memory with all instances of the class

	// Called in constructor to ensure ID is set correctly
	void SetID(int val);
};

#endif // !BASEGAMEENTITY_H

