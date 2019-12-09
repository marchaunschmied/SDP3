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
// CTor passes data path to Revolution Sensor 
// if no value is specified default file name is passed
///////////////////////////////////////////////////////////////////////////
Car::Car(std::string const& path) : mRevoSensor(path) {}


///////////////////////////////////////////////////////////////////////////
//Evaluates sensor value and saves the speed, then notifies all Observers
///////////////////////////////////////////////////////////////////////////
void Car::Process()
{
	//Current Speed = (Revolutions / Seconds) * Tire Circumference

	try {
		mCurrentSpeed = (mRevoSensor.GetRevolutions() * 1.0 / seconds) * TireCircumference;
		//Tell all Observers that a new value is ready;
		Vehicle::Notify();
	}
	catch (std::string ex) {
		throw std::string{ ex };
	}
}

///////////////////////////////////////////////////////////////////////////
//Get Methods
///////////////////////////////////////////////////////////////////////////
double Car::GetCurrentSpeed() const
{
	return mCurrentSpeed;
}
