///////////////////////////////////////////////////////////////////////////
// Workfile :		Fleet.h
// Author :			Markus Riegler
// Date :			25.10.2019
// Description :	Header for the class Fleet
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef FLEET_H
#define FLEET_H

#include <list>
#include <memory>
#include <numeric>
#include <algorithm>
#include "Object.h"
#include "Vehicle.h"

typedef std::list<Vehicle::SPtr> FleetCont;

class Fleet : public Object
{
public:
	//When Copy-Ctor is implemented, then no implizit default CTor
	Fleet() = default;

	//DTor not needed because of smart pointers
	~Fleet() override = default;

	//Adds the given Vehicle
	bool AddVehicle(Vehicle::SPtr const& v);

	//Deletes the Vehicle with the given Licenseplate
	bool RemoveVehicle(std::string const& LicensePlate);

	//Returns an uniqu_ptr to the found vehicle
	Vehicle::SPtr Find(std::string const& LicensePlate) const;

	//Returns the distance of all Vehicles in the Fleet
	size_t GetTotalDistance() const;

	//Prints all Vehicles in the fleet
	void Print(std::ostream& ost) const;

private:
	
	FleetCont mFleet;

	//Function to search for a Vehicle with an given 
	FleetCont::const_iterator FindLP(std::string const& l) const;

};

std::ostream& operator<<(std::ostream& ost, Fleet const& f);

#endif // !FLEET_H