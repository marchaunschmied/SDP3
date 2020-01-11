///////////////////////////////////////////////////////////////////////////
// Workfile :		CoffeeNames.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Namespace for Coffee names
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef COFFEENAMES_H
#define COFFEENAMES_H

#include <string>

namespace CoffeeNames {
	//-----------------Coffee-------------------------
	std::string const Americano     = "Verlaengerter";
	std::string const Decaf         = "Koffeinfrei";
	std::string const Espresso      = "Espresso";
	std::string const Mocca         = "Mocca";

	//-----------------Ingredients--------------------
	std::string const Milk          = "Milch";
	std::string const SoyMilk       = "Sojamilch";
	std::string const Sugar         = "Zucker";
	std::string const WhippedCream  = "Schlagobers";

	//------------------Formation---------------------
	std::string const CoffeeSep     = ": ";
	std::string const IngredientSep = ", ";
}
#endif
