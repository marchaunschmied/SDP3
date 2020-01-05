///////////////////////////////////////////////////////////////////////////
// Workfile :		Espresso.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Espresso
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Espresso.h"

//returns price of an Espresso from the Pricelist
double Espresso::GetCost() const
{
	return CoffeePriceList::Espresso;
}

//returns Name of Espresso from the Namelist + seperator
std::string Espresso::GetDescription() const
{
	return CoffeeNames::Espresso + CoffeeNames::CoffeeSep;
}
