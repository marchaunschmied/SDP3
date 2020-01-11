///////////////////////////////////////////////////////////////////////////
// Workfile :		CoffeePriceList.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Namespace for prices
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef COFFEPRICELIST_H
#define COFFEPRICELIST_H


namespace CoffeePriceList {
	std::string const Currency = "Euro";
	//-----------------Coffee----------------------
	double const Americano    = 2.10;
	double const Decaf        = 2.25;
	double const Espresso     = 2.80;
	double const Mocca        = 3.10;

	//-----------------Ingredients-----------------
	double const Milk         = 0.15;
	double const SoyMilk      = 0.20;
	double const Sugar        = 0.12;
	double const WhippedCream = 0.28;
}

#endif

