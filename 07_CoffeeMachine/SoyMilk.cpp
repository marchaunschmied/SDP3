#include "SoyMilk.h"

double SoyMilk::GetCost() const
{
	return CoffeePriceList::SoyMilk + mComponent->GetCost();
}

std::string SoyMilk::GetDescription() const
{
	std::string prevDes = mComponent->GetDescription();
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		return prevDes + CoffeeNames::SoyMilk;
	}
	else
	{
		return prevDes + CoffeeNames::IngredientSep + CoffeeNames::SoyMilk;
	}
}

SoyMilk::SoyMilk(Coffee::SPtr coffee): Ingredient{coffee}
{
}
