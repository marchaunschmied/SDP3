///////////////////////////////////////////////////////////////////////////
// Workfile :		Car.h
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Header for the from Vehicle derived class Car
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(std::string const& brand, std::string const& model,
		std::string const& licensePlate, TFuel const fuel);
	~Car() override = default;

protected:
	std::string WhichVehicle() const override;
};

#endif // !CAR_H