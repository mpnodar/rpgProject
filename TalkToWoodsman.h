#pragma once
#include "Action.h"
#include "ManChoppingWood.h"
class TalkToWoodsman : public Action
{
public:
	TalkToWoodsman(GameMap* gm);
	ActionResponse execute(player* p) override;
};

