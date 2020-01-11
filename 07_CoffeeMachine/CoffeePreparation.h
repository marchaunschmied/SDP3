///////////////////////////////////////////////////////////////////////////
// Workfile :		CoffeePreparation.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class CoffeePreparation
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef COFFEEPREPARATION_H
#define COFFEEPREPARATION_H

#include <iostream>
#include <deque>
#include <iomanip>
#include "Object.h"
#include "ICoffee.h"

class CoffeePreparation : public Object {
public:
	void Prepare(ICoffee::SPtr coffee); //adds and prepares a coffee
	void Display(std::ostream & os) const; //outputs all coffees in preparation
	ICoffee::SPtr Finished(); //removes the prepared coffee
private:
	//Container for Coffees in preparation
	std::deque<ICoffee::SPtr> mCoffeeQueue;
};

#endif
