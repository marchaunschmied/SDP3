#include "Sugar.h"

double Sugar::GetCost() const
{
	return CoffeePriceList::Sugar + mComponent->GetCost();
}

std::string Sugar::GetDescription() const
{
	std::string prevDes = mComponent->GetDescription();
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		return prevDes + CoffeeNames::Sugar;
	}
	else
	{
		return prevDes + CoffeeNames::IngredientSep + CoffeeNames::Sugar;
	}
}

Sugar::Sugar(Coffee::SPtr coffee): Ingredient{coffee}
{
}
