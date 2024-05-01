#pragma once
#include "Action.h"
#include "ShadyPerson.h"
class TalkToShadyPerson : public Action
{
public:
	TalkToShadyPerson(GameMap* gm);
	ActionResponse execute(player* p) override;
};

