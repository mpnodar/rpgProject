#pragma once
#include <string>
#include "TalkingNPC.h"
#include "characters.h"
class Action
{
public:
	std::string description;
	virtual void execute(player*);
};

