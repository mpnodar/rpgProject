#pragma once
#include <string>
#include "TalkingNPC.h"
class Action
{
public:
	std::string description;
	virtual void execute();
};

