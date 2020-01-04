#ifndef WHIPPEDCREAM_H
#define WHIPPEDCREAM_H

#include "Ingredient.h"

class WhippedCream : public Ingredient {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
	WhippedCream(Coffee::SPtr coffee);
};

#endif

