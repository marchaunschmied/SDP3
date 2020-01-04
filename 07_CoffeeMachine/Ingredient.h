#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Object.h"
#include "Coffee.h"

class Ingredient : public Coffee, public Object {
public:
	virtual double GetCost() const = 0;
	virtual std::string GetDescription() const = 0;
protected:
	Ingredient(Coffee::SPtr coffee);
private:
	Coffee::SPtr mComponent;
};

#endif
