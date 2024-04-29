#pragma once
#include "Action.h"
#include "shop.h"

class ShoppingAction : public Action
{
private:
	shop* store;
public:
	void setShop(shop* s);
	ActionResponse execute(player*) override;
};

