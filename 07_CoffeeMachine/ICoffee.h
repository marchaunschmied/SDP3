///////////////////////////////////////////////////////////////////////////
// Workfile :		ICoffee.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Interface for Coffee
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <memory>

#include "CoffeeNames.h"
#include "CoffeePriceList.h"

class ICoffee {
public:
	//typedefs
	using SPtr = std::shared_ptr<ICoffee>;
	//Interface functions
	virtual double GetCost() const = 0;
	virtual std::string GetDescription() const = 0;
protected:
	ICoffee() = default;
};

#endif
