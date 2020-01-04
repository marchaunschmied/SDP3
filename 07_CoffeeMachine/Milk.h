#ifndef MILK_H
#define MILK_H

#include "Ingredient.h"

class Milk : public Ingredient {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
	Milk(Coffee::SPtr coffee);
};

#endif
