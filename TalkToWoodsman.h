#pragma once
#include "Action.h"
#include "ManChoppingWood.h"
class TalkToWoodsman : public Action
{
public:
	TalkToWoodsman();
	ActionResponse execute(player* p) override;
};

