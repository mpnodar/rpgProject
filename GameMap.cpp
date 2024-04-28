#include "GameMap.h"

GameMap::GameMap()
{
	locations["TownSquare"] = new TownSquare(this);
	locations["Merchant"] = new Merchant(this);
	locations["RoadToWoods"] = new RoadToWoods(this);
	locations["ShadyPeople"] = new ShadyPeople(this);
	locations["Beast"] = new Beast(this);
	locations["OrcCamp"] = new OrcCamp(this);
	locations["PathThroughWoods"] = new PathThroughWoods(this);
}

GameMap::~GameMap()
{
	delete locations["TownSquare"];
	delete locations["Merchant"];
	delete locations["RoadToWoods"];
	delete locations["ShadyPeople"];
	delete locations["Beast"];
	delete locations["OrcCamp"];
	delete locations["PathThroughWoods"];
}

void GameMap::play(player* p)
{
	locations["TownSquare"]->execLocation(p);
}
