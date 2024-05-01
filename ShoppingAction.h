#pragma once
#include "Action.h"
#include "shop.h"

class ShoppingAction : public Action
{
private:
	shop* store;
public:
	ShoppingAction(GameMap* gm);
	void setShop(shop* s);
	ActionResponse execute(player*) override;
};

