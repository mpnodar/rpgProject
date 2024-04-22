#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Action.h"

class GameMap;

class Location
{
public:
	GameMap* gameMap;
	std::map<std::string, Location*> locations;
	std::string description;
	double probabilityOfMonsterEncounter;
	std::vector<Action*> actions;
	void execLocation();
	Location(GameMap* m);
};