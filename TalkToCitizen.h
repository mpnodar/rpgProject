#pragma once
#include "Action.h"
#include "ManChoppingWood.h"

class TalkToCitizen : public Action
{
public:
	TalkToCitizen();
	ActionResponse execute(player* p) override;
};

