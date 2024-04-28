#pragma once
#include "Action.h"
#include "gameMenu.h"
class GameMenuAction : public Action
{
public:
	GameMenuAction();
	void execute(player* p) override;
};

