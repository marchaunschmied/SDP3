///////////////////////////////////////////////////////////////////////////
// Workfile :		Milk.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class Milk
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Milk.h"


///////////////////////////////////////////////////////////////////////////
//GetMethods
///////////////////////////////////////////////////////////////////////////
std::string Milk::GetIngredientName() const
{
	return CoffeeNames::Milk;
}

double Milk::GetIngredientCost() const
{
	return CoffeePriceList::Milk;
}

///////////////////////////////////////////////////////////////////////////
//CTor passes coffee to the base class
///////////////////////////////////////////////////////////////////////////
Milk::Milk(ICoffee::SPtr coffee): Ingredient{coffee}
{
}
