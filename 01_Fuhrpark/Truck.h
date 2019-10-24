///////////////////////////////////////////////////////////////////////////
// Workfile :		Truck.h
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Header for the from Vehicle derived Class Truck
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <iostream>
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck(std::string const& brand, std::string const& model,
		  std::string const& licensePlate, TFuel const fuel);
	~Truck() override = default;

protected:
	std::string WhichVehicle() const override;
};

#endif // !TRUCK_H
