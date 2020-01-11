///////////////////////////////////////////////////////////////////////////
// Workfile :		WhippedCream.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class WhippedCream
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef WHIPPEDCREAM_H
#define WHIPPEDCREAM_H

#include "Ingredient.h"

class WhippedCream : public Ingredient {
public:
	//functions from Ingredient
	virtual std::string GetIngredientName() const override;
	virtual double GetIngredientCost() const override;

	WhippedCream(ICoffee::SPtr coffee);
};

#endif

