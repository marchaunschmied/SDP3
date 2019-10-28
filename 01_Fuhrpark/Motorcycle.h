///////////////////////////////////////////////////////////////////////////
// Workfile :		Motorcycle.h
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Header for the from Vehicle derived class Motorcycle
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include <iostream>
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle(std::string const& brand, std::string const& model,
			   std::string const& licensePlate, TFuel const fuel);
	~Motorcycle() override = default;

protected:
	std::string WhichVehicle() const override;
};

#endif // !MOTORCYCLE_H
