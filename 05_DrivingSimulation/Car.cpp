#include "Car.h"

void Car::Process()
{
	mCurrentSpeed = (mRevoSensor.GetRevolutions() / 60) * 0, 6 * 3.1415 * 3.6;
	Vehicle::Notify();
}

double Car::GetCurrentSpeed() const
{
	return mCurrentSpeed;
}
