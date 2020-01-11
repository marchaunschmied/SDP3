///////////////////////////////////////////////////////////////////////////
// Workfile :		Decaf.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Decaf
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Decaf.h"

//returns price of a Decaf from the Pricelist
double Decaf::GetCost() const
{
	return CoffeePriceList::Decaf;
}

//returns Name of Decaf from the Namelist + seperator
std::string Decaf::GetDescription() const
{
	return CoffeeNames::Decaf + CoffeeNames::CoffeeSep;
}
