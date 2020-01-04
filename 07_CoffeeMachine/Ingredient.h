#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Object.h"
#include "Coffee.h"

#include "CoffeeNames.h"
#include "CoffeePriceList.h"

class Ingredient : public Coffee, public Object {
public:
	virtual double GetCost() const = 0;
	virtual std::string GetDescription() const = 0;
protected:
	Ingredient(Coffee::SPtr coffee);
	Coffee::SPtr mComponent;
};

#endif
