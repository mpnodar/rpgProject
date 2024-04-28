#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Action.h"
#include "characters.h"
#include "GameMenuAction.h"

class GameMap;

class Location
{
private:
	GameMenuAction menuAction;
public:
	GameMap* gameMap;
	std::map<std::string, Location*> locations;
	std::string description;
	double probabilityOfMonsterEncounter;
	std::vector<Action*> actions;
	void execLocation(player*);
	Location(GameMap* m);
	void addGameMenu();
};