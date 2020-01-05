///////////////////////////////////////////////////////////////////////////
// Workfile :		Ingredient.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of abstract base class Ingredient
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Object.h"
#include "ICoffee.h"

#include "CoffeeNames.h"
#include "CoffeePriceList.h"

class Ingredient : public ICoffee, public Object {
public:
	//functions from interface Coffee
	virtual double GetCost() const = 0;
	virtual std::string GetDescription() const = 0;
protected:
	//protected CTor
	Ingredient(ICoffee::SPtr coffee);
	//make it a Composite
	ICoffee::SPtr mComponent;
};

#endif
