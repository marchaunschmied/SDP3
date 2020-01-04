#ifndef SOYMILK_H
#define SOYMILK_H

#include "Ingredient.h"

class SoyMilk : public Ingredient {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
	SoyMilk(Coffee::SPtr coffee);
};

#endif

