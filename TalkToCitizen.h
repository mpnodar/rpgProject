#pragma once
#include "Action.h"
#include "Citizen.h"

class TalkToCitizen : public Action
{
public:
	TalkToCitizen();
	ActionResponse execute(player* p) override;
};

