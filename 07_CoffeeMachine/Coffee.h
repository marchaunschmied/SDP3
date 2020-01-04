#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <memory>

#include "CoffeeNames.h"
#include "CoffeePriceList.h"

class Coffee {
public:
	using SPtr = std::shared_ptr<Coffee>;
	virtual double GetCost() const = 0;
	virtual std::string GetDescription() const = 0;
protected:
	Coffee() = default;
};

#endif
