#pragma once
#include "Action.h"
#include "GameMap.h"
class EnemyAttackAction : public Action
{
private:
	enemy* monster;
public:
	EnemyAttackAction(GameMap* gm);
	void setEnemy(enemy* e);
	ActionResponse execute(player*) override;
	bool isBeastQuest = false;
	bool isOrcQuest = false;
};

