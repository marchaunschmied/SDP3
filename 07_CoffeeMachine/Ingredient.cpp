///////////////////////////////////////////////////////////////////////////
// Workfile :		Ingredient.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of abstract base class Ingredient
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Ingredient.h"

///////////////////////////////////////////////////////////////////////////
//returns the cost of actual ingredient + the cost of Component
///////////////////////////////////////////////////////////////////////////
double Ingredient::GetCost() const
{
	return mComponent->GetCost() + GetIngredientCost();
}

///////////////////////////////////////////////////////////////////////////
// returns the name of the actual ingredient + description of component
// with the right formation.
///////////////////////////////////////////////////////////////////////////
std::string Ingredient::GetDescription() const
{
	//get the description of the Component
	std::string prevDes = mComponent->GetDescription();

	//Check if previuos was a concrete coffee
	if (prevDes.compare(prevDes.size() - CoffeeNames::CoffeeSep.size(),
		CoffeeNames::CoffeeSep.size(), CoffeeNames::CoffeeSep) == 0)
	{
		// Yes -> just add Milk description
		return prevDes + GetIngredientName();
	}
	else
	{
		// No -> add the seperator in between
		return prevDes + CoffeeNames::IngredientSep + GetIngredientName();
	}
}

///////////////////////////////////////////////////////////////////////////
//CTor sets the Composite connection
///////////////////////////////////////////////////////////////////////////
Ingredient::Ingredient(ICoffee::SPtr coffee)
{
	if (coffee == nullptr)
	{
		throw std::string("Nullpointer in CTor of Ingredient");
	}
	else
	{
		mComponent = coffee;
	}
}
