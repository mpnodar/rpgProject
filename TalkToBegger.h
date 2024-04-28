#pragma once
#include "Action.h"
#include "RoadsideBeggar.h"

class TalkToBegger : public Action
{
public:
	TalkToBegger();
	void execute(player* p) override;
};

