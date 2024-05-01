#pragma once
#include "Location.h"
#include "GameMap.h"
class Beast : public Location
{
public:
	Beast(GameMap* m);
	void generateActions() override;
};

