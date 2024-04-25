#pragma once
#include <map>
#include <string>
#include "Location.h"
#include "TownSquare.h"
#include "Merchant.h"
#include "RoadToWoods.h"

class Location;

class GameMap
{
public:
	std::map<std::string, Location*> locations;
	GameMap();
	~GameMap();
	void play();
};

