///////////////////////////////////////////////////////////////////////////
// Workfile :		Sugar.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Sugar
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef SUGAR_H
#define SUGER_H

#include "Ingredient.h"

class Sugar : public Ingredient {
public:
	//functions from Ingredient
	virtual std::string GetIngredientName() const override;
	virtual double GetIngredientCost() const override;

	Sugar(ICoffee::SPtr coffee);
};

#endif
