///////////////////////////////////////////////////////////////////////////
// Workfile :		Vehicle.cpp
// Author :			Markus Riegler
// Date :			24.10.2019
// Description :	Implementation of class Vehicle
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#include "Vehicle.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//CTor with all parameters
//A Vehicle can only be initialised through the CTor
///////////////////////////////////////////////////////////////////////////
Vehicle::Vehicle(std::string const& brand, std::string const& model,
				 std::string const& licensePlate, TFuel const fuel) :
 mBrand{ brand }, mModel{ model }, mLicensePlate(licensePlate), mFuel(fuel)
{
}

///////////////////////////////////////////////////////////////////////////
//constant for the column width of the output
//omanip implemented, to format the first column of the output
///////////////////////////////////////////////////////////////////////////
size_t const colwidth = 13;
std::ostream& col(std::ostream& ost)
{
	ost << setw(colwidth) << left << setfill(' ');
	return ost;
}

///////////////////////////////////////////////////////////////////////////
//Prints all Data to the given ostream
//Throws an exception when the given stream is not OK
//Uses the Template-Method-Pattern to print its type
///////////////////////////////////////////////////////////////////////////
void Vehicle::Print(std::ostream& ost) const
{
	if (!ost.good())
	{
		throw std::string("Stream Error");
	}

	ost << col << "Fahrzeugart:" << WhichVehicle() << endl;
	ost << col << "Marke:" << mBrand << " " << mModel << endl;
	ost << col << "Kennzeichen:" << mLicensePlate << endl;

	mLogBook.PrintLog(ost);
}

///////////////////////////////////////////////////////////////////////////
//Passes all arguments to the LogBook
///////////////////////////////////////////////////////////////////////////
bool Vehicle::AddLogEntry(std::string const& date, size_t const& distance)
{
	return mLogBook.AddEntry(date, distance);
}

///////////////////////////////////////////////////////////////////////////
//Get-Methods
///////////////////////////////////////////////////////////////////////////
std::string Vehicle::GetLicensePlate() const
{
	return mLicensePlate;
}

size_t Vehicle::GetTotalDistance() const
{
	return mLogBook.SumDistance();
}