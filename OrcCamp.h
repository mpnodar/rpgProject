#pragma once
#include "Location.h"
#include "GameMap.h"
class OrcCamp : public Location
{
public:
	OrcCamp(GameMap* m);
	void generateActions() override;
};

