///////////////////////////////////////////////////////////////////////////
// Workfile :		Mocca.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Mocca
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Mocca.h"

//returns price of a Mocca from the Pricelist
double Mocca::GetCost() const
{
	return CoffeePriceList::Mocca;
}

//returns Name of Mocca from the Namelist + seperator
std::string Mocca::GetDescription() const
{
	return CoffeeNames::Mocca + CoffeeNames::CoffeeSep;
}
