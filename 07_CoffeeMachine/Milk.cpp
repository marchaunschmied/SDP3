///////////////////////////////////////////////////////////////////////////
// Workfile :		Milk.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Milk
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Milk.h"

///////////////////////////////////////////////////////////////////////////
//returns the cost from Milk + the cost of the Component
///////////////////////////////////////////////////////////////////////////
double Milk::GetCost() const
{
	return CoffeePriceList::Milk + mComponent->GetCost();
}

///////////////////////////////////////////////////////////////////////////
//returns Description of Milk + the description of component
///////////////////////////////////////////////////////////////////////////
std::string Milk::GetDescription() const
{
	//get the description of the Component
	std::string prevDes = mComponent->GetDescription();

	//Check if previuos was a concrete coffee
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(), 
		CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		// Yes -> just add Milk description
		return prevDes + CoffeeNames::Milk;
	}
	else
	{
		// No -> add the seperator in between
		return prevDes + CoffeeNames::IngredientSep + CoffeeNames::Milk;
	}
}

///////////////////////////////////////////////////////////////////////////
//CTor passes coffee to the base class
///////////////////////////////////////////////////////////////////////////
Milk::Milk(ICoffee::SPtr coffee): Ingredient{coffee}
{
}
