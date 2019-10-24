///////////////////////////////////////////////////////////////////////////
// Workfile :		Vehicle.h
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Base class of all Vehicle types
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Object.h"
#include "LogBook.h"

//enum for the type of Fuel
enum class TFuel { DIESEL, PETROL, NATURAL_GAS, ELECTRIC };

class Vehicle : public Object
{
public:

	//Everything has to be set while initialising
	Vehicle(std::string const& brand, std::string const& model,
			std::string const& licensePlate, TFuel const fuel);

	//No extra DTor needed
	~Vehicle() override = default;

	//Prints data from the Vehicle and all Logbook entries
	//Template-Method which calls WhichVehicle to determine
	//the type
	void Print(std::ostream& ost) const;

	//Adds an entry into its logbook
	bool AddLogEntry(std::string const& date, size_t const& distance);

	//Getter Methods
	std::string GetLicensePlate() const;
	size_t GetTotalDistance() const;

protected:
	//Has to be overwritten from derived classes
	virtual std::string WhichVehicle() const = 0;

private:
	std::string mBrand;
	std::string mModel;
	std::string mLicensePlate;
	TFuel mFuel;
	LogBook mLogBook;
};
#endif // !VEHICLE_H









