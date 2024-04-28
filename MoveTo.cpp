#include "MoveTo.h"
#include "GameMap.h"

ActionResponse MoveTo::execute(player* p)
{
	return gameMap->locations[moveToLocation]->execLocation(p);
}
