#include "WhippedCream.h"

double WhippedCream::GetCost() const
{
	return CoffeePriceList::WhippedCream + mComponent->GetCost();
}

std::string WhippedCream::GetDescription() const
{
	std::string prevDes = mComponent->GetDescription();
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		return prevDes + CoffeeNames::WhippedCream;
	}
	else
	{
		return prevDes + CoffeeNames::IngredientSep + CoffeeNames::WhippedCream;
	}
}

WhippedCream::WhippedCream(Coffee::SPtr coffee): Ingredient{coffee}
{
}
