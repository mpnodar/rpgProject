#include "GameMap.h"

GameMap::GameMap()
{
	locations["TownSquare"] = new TownSquare(this);
	locations["Merchant"] = new Merchant(this);
}

GameMap::~GameMap()
{
	delete locations["TownSquare"];
	delete locations["Merchant"];
}

void GameMap::play()
{
	locations["TownSquare"]->execLocation();
}
