///////////////////////////////////////////////////////////////////////////
// Workfile :		Milk.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Milk
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef MILK_H
#define MILK_H

#include "Ingredient.h"

class Milk : public Ingredient {
public:
	//functions from interface Coffee
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;

	Milk(ICoffee::SPtr coffee);
};

#endif
