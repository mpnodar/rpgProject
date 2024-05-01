#pragma once
#include "Action.h"
#include "Citizen.h"

class TalkToCitizen : public Action
{
public:
	TalkToCitizen(GameMap* gm);
	ActionResponse execute(player* p) override;
};

