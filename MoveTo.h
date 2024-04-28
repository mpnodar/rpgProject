#pragma once
#include "Action.h"
#include "Location.h"
#include "characters.h"
#include "battleSequence.h"
#include <string>
#include <map>
#include <random>
#include <cstdlib>

class MoveTo : public Action
{
public:
	GameMap* gameMap;
	std::string moveToLocation;
	ActionResponse execute(player*) override;
};

