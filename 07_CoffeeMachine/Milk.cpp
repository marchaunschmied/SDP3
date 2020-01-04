#include "Milk.h"

double Milk::GetCost() const
{
	return CoffeePriceList::Milk + mComponent->GetCost();
}

std::string Milk::GetDescription() const
{
	std::string prevDes = mComponent->GetDescription();
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		return prevDes + CoffeeNames::Milk;
	}
	else
	{
		return prevDes + CoffeeNames::IngredientSep + CoffeeNames::Milk;
	}
}

Milk::Milk(Coffee::SPtr coffee): Ingredient{coffee}
{
}
