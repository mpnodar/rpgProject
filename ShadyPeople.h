#pragma once
#include "Location.h"
#include "GameMap.h"
#include "TalkToShadyPerson.h"
class ShadyPeople : public Location
{
public:
	ShadyPeople(GameMap* m);
	void generateActions() override;
};

