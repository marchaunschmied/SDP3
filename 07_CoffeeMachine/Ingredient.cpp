///////////////////////////////////////////////////////////////////////////
// Workfile :		Ingredient.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of abstract base class Ingredient
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Ingredient.h"

//CTor sets the Composite connection
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
