#include "Decaf.h"

double Decaf::GetCost() const
{
	return CoffeePriceList::Decaf;
}

std::string Decaf::GetDescription() const
{
	return CoffeeNames::Decaf + CoffeeNames::CoffeeSep;
}
