#ifndef SUGAR_H
#define SUGER_H

#include "Ingredient.h"

class Sugar : public Ingredient {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
	Sugar(Coffee::SPtr coffee);
};

#endif
