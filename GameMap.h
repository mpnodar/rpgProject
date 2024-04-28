#pragma once
#include <map>
#include <string>
#include "Location.h"
#include "TownSquare.h"
#include "Merchant.h"
#include "RoadToWoods.h"
#include "characters.h"
#include "gameMenu.h"
#include "ShadyPeople.h"
#include "Beast.h"
#include "OrcCamp.h"
#include "PathThroughWoods.h"

class Location;

class GameMap
{
public:
	std::map<std::string, Location*> locations;
	GameMap();
	~GameMap();
	void play(player*);
	gameMenu m;
};

