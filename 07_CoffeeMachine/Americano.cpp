///////////////////////////////////////////////////////////////////////////
// Workfile :		Americano.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Americano
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Americano.h"

//returns price of an Americano from the Pricelist
double Americano::GetCost() const
{
	return CoffeePriceList::Americano;
}

//returns Name of Americano from the Namelist + seperator
std::string Americano::GetDescription() const
{
	return CoffeeNames::Americano + CoffeeNames::CoffeeSep;
}
