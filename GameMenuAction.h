#pragma once
#include "Action.h"
#include "gameMenu.h"
#include "ActionResponse.h"
class GameMenuAction : public Action
{
public:
	GameMenuAction();
	ActionResponse execute(player* p) override;
};

