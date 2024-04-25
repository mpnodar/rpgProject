#include "GameMap.h"

GameMap::GameMap()
{
	locations["TownSquare"] = new TownSquare(this);
	locations["Merchant"] = new Merchant(this);
	locations["RoadToWoods"] = new RoadToWoods(this);
}

GameMap::~GameMap()
{
	delete locations["TownSquare"];
	delete locations["Merchant"];
	delete locations["RoadToWoods"];
}

void GameMap::play()
{
	locations["TownSquare"]->execLocation();
}
