#include "Espresso.h"

double Espresso::GetCost() const
{
	return CoffeePriceList::Espresso;
}

std::string Espresso::GetDescription() const
{
	return CoffeeNames::Espresso + CoffeeNames::CoffeeSep;
}
