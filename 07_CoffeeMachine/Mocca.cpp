#include "Mocca.h"

double Mocca::GetCost() const
{
	return CoffeePriceList::Mocca;
}

std::string Mocca::GetDescription() const
{
	return CoffeeNames::Mocca + CoffeeNames::CoffeeSep;
}
