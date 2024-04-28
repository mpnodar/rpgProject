#include "MoveTo.h"
#include "GameMap.h"

void MoveTo::execute(player* p)
{
	gameMap->locations[moveToLocation]->execLocation(p);
}
