#pragma once
#include <string>
#include "TalkingNPC.h"
#include "characters.h"
#include "ActionResponse.h"

class GameMap;

class Action
{
public:
	GameMap* gameMap;
	Action(GameMap* gm);
	std::string description;
	virtual ActionResponse execute(player*);
};

