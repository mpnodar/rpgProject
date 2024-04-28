#pragma once
#include "Action.h"
#include "ShadyPerson.h"
class TalkToShadyPerson : public Action
{
public:
	TalkToShadyPerson();
	ActionResponse execute(player* p) override;
};

