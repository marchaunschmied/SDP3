#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "RevolutionSensor.h"

class Car :	public Vehicle {
public:
	void Process();
	double GetCurrentSpeed();
private:
	double mCurrentSpeed;
	RevolutionSensor mRevoSensor;
};

#endif