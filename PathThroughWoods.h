#pragma once
#include "Location.h"
#include "TalkToWoodsman.h"
class PathThroughWoods : public Location
{
public:
	PathThroughWoods(GameMap* m);
	void generateActions() override;
};

