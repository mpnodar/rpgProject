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
#include "hashTable.h"
#include "hashNode.h"
#include "Armorer.h"
#include <random>

class Location;

class GameMap
{
private:
	hashTable* HT = new hashTable(3);
	player* user;
public:
	std::map<std::string, Location*> locations;
	GameMap();
	~GameMap();
	void play(player*);
	gameMenu m;
	enemy* getRandomMonster(std::string locationName);
};

