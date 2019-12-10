///////////////////////////////////////////////////////////////////////////
// Workfile :		Car.h
// Author :			Markus Riegler
// Date :			05-December-2019
// Description :	Header of class Car
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "RevolutionSensor.h"

class Car :	public Vehicle {
public:
	//Process evaluates the sensor
	void Process();
	//GetMethod for speed
	double GetCurrentSpeed() const;
	using SPtr = std::shared_ptr<Car>;

	Car(std::string const& path = "Revolutions.txt");


private:
	double mCurrentSpeed;
	RevolutionSensor mRevoSensor;
};

#endif