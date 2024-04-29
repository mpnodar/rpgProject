#pragma once
#include "Action.h"
#include "GameMap.h"
class EnemyAttackAction : public Action
{
private:
	enemy* monster;
public:
	void setEnemy(enemy* e);
	ActionResponse execute(player*) override;
};

