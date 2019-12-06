///////////////////////////////////////////////////////////////////////////
// Workfile :		Car.cpp
// Author :			Markus Riegler
// Date :			05-December-2019
// Description :	Implematation of class Car
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#include "Car.h"

//Constants for calculation
size_t const seconds = 60; // seconds per minute
double const TireCircumference = 0.6 * 3.1415;

///////////////////////////////////////////////////////////////////////////
//Evaluates sensor value and saves the speed, then notifies all Observers
///////////////////////////////////////////////////////////////////////////
void Car::Process()
{
	//Current Speed = (Revolutions / Seconds) * Tire Circumference

	mCurrentSpeed = (mRevoSensor.GetRevolutions()* 1.0 / seconds) * TireCircumference;
	//Tell all Observers that a new value is ready;
	Vehicle::Notify();
}

///////////////////////////////////////////////////////////////////////////
//Get Methods
///////////////////////////////////////////////////////////////////////////
double Car::GetCurrentSpeed() const
{
	return mCurrentSpeed;
}
