///////////////////////////////////////////////////////////////////////////
// Workfile :		Car.cpp
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Implementation of class Car
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#include "Car.h"

///////////////////////////////////////////////////////////////////////////
//CTor passes all arguments to its base class
///////////////////////////////////////////////////////////////////////////
Car::Car(std::string const& brand, std::string const& model,
		 std::string const& licensePlate, TFuel const fuel):
	Vehicle{brand, model, licensePlate, fuel}
{
}

///////////////////////////////////////////////////////////////////////////
//Overwrites the function to give back its type
///////////////////////////////////////////////////////////////////////////
std::string Car::WhichVehicle() const
{
	return "PKW";
}
