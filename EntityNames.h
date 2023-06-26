#ifndef NAMES_H
#define NAMES_H
#include <string>

enum
{
	entity_Miner_Bob,

};

inline std::string GetNameOfEntity(int id)
{
	switch(id)
	{
	case entity_Miner_Bob:
		return "Miner Bob";
	}
}

#endif // !NAMES_H
