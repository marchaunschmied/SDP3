#ifndef COFFEEPREPARATION_H
#define COFFEEPREPARATION_H

#include <iostream>
#include <deque>
#include <iomanip>
#include "Object.h"
#include "Coffee.h"

class CoffeePreparation : public Object {
public:
	void Prepare(Coffee::SPtr coffee); //adds and prepares a coffee
	void Display(std::ostream & os); //outputs all coffees in preparation
	Coffee::SPtr Finished(); //removes the prepared coffeey
private:
	std::deque<Coffee::SPtr> mCoffeeQueue;
};

#endif
