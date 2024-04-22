#include "MoveTo.h"
#include "GameMap.h"

void MoveTo::execute()
{
	gameMap->locations[moveToLocation]->execLocation();
}
