///////////////////////////////////////////////////////////////////////////
// Workfile :		SoyMilk.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class SoyMilk
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef SOYMILK_H
#define SOYMILK_H

#include "Ingredient.h"

class SoyMilk : public Ingredient {
public:
	//functions from Ingredient
	virtual std::string GetIngredientName() const override;
	virtual double GetIngredientCost() const override;
	
	SoyMilk(ICoffee::SPtr coffee);
};

#endif

