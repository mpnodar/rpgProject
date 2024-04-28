#pragma once
#include "Action.h"
#include "RoadsideBeggar.h"

class TalkToBegger : public Action
{
public:
	TalkToBegger();
	ActionResponse execute(player* p) override;
};

