#pragma once
#include "Action.h"
#include "Location.h"
#include <string>
#include <map>

class MoveTo : public Action
{
public:
	GameMap* gameMap;
	std::string moveToLocation;
	void execute() override;
};

