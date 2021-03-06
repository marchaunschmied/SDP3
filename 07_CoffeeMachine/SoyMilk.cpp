///////////////////////////////////////////////////////////////////////////
// Workfile :		SoyMilk.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implemtation of class SoyMilk
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "SoyMilk.h"

///////////////////////////////////////////////////////////////////////////
//GetMethods
///////////////////////////////////////////////////////////////////////////
std::string SoyMilk::GetIngredientName() const
{
	return CoffeeNames::SoyMilk;
}

double SoyMilk::GetIngredientCost() const
{
	return CoffeePriceList::SoyMilk;
}

///////////////////////////////////////////////////////////////////////////
//CTor passes coffee to the base class
///////////////////////////////////////////////////////////////////////////
SoyMilk::SoyMilk(ICoffee::SPtr coffee): Ingredient{coffee}
{
}
