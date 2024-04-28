#pragma once
#include <string>
#include "TalkingNPC.h"
#include "characters.h"
#include "ActionResponse.h"
class Action
{
public:
	std::string description;
	virtual ActionResponse execute(player*);
};

