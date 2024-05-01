#include "ShoppingAction.h"

ShoppingAction::ShoppingAction(GameMap* gm) : Action(gm)
{
}

void ShoppingAction::setShop(shop* s)
{
	store = s;
}

ActionResponse ShoppingAction::execute(player* p)
{
	std::system("cls");
	
	store->displayGoods(p);
	return LeftShop;
}
