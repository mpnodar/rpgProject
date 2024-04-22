#pragma once
#include "Action.h"
#include "ManChoppingWood.h"

class TalkToCitizen : public Action
{
public:
	TalkToCitizen();
	void execute() override;
};

