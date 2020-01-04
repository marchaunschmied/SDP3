#include "Americano.h"

double Americano::GetCost() const
{
	return CoffeePriceList::Americano;
}

std::string Americano::GetDescription() const
{
	return CoffeeNames::Americano + CoffeeNames::CoffeeSep;
}
