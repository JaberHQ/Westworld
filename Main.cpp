#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Miner.h"
#include "EntityNames.h"
int main()
{
	Miner miner(entity_Miner_Bob);

	for(int i =0; i < 20; i++)
	{
		miner.Update();

		Sleep(800);
	}
	return 0;
}