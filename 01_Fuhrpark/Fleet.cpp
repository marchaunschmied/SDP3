///////////////////////////////////////////////////////////////////////////
// Workfile :		Fleet.h
// Author :			Markus Riegler
// Date :			25.10.2019
// Description :	Implementation of class Fleet
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "Fleet.h"

//Fleet::Fleet(Fleet const& f)
//{
//	Copy(f);
//}
//
//Fleet& Fleet::operator=(Fleet const& f)
//{
//	if (&f != this)
//	{
//		mFleet.clear();
//		Copy(f);
//	}
//	return *this;
//}

///////////////////////////////////////////////////////////////////////////
//Adds the given Vehicle to the Container, if there isn´t already one
//with the same license plate.
//returns true if added
//returns false when not added
///////////////////////////////////////////////////////////////////////////
bool Fleet::AddVehicle(Vehicle::SPtr const& v)
{
	//Valid input?
	if (v == nullptr) 
	{ 
		throw std::invalid_argument
						{ "null_pointer in Fleet::AddVehicle(...)" }; 
	}
	//Add if not already contained
	if (FindLP(v->GetLicensePlate()) == mFleet.cend())
	{
		mFleet.emplace_back(v);
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////
//Removes the Vehicle with the given license plate
//returns true if contained and deleted
//returns false when there is no vehicle with given license plate
///////////////////////////////////////////////////////////////////////////
bool Fleet::RemoveVehicle(std::string const& LicensePlate)
{
	//Get the iterator
	auto it = FindLP(LicensePlate);
	//Delete if contained
	if (it != mFleet.cend())
	{
		mFleet.erase(it);
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////
//Searches for a vehicle with an specific license plate
//returns shared pointer to element if found
//returns nullpointer if not found
///////////////////////////////////////////////////////////////////////////
Vehicle::SPtr Fleet::Find(std::string const& LicensePlate) const
{
	auto it = FindLP(LicensePlate);
	if (it != mFleet.cend())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}

///////////////////////////////////////////////////////////////////////////
//Adds up all the distances from every vehicle
//returns driven km
///////////////////////////////////////////////////////////////////////////
size_t Fleet::GetTotalDistance() const
{
	//Start value = 0
	return std::accumulate(mFleet.cbegin(), mFleet.cend(), 0,
				[](size_t const d, Vehicle::SPtr const& v) 
					{ return d + v->GetTotalDistance(); });
}

///////////////////////////////////////////////////////////////////////////
//Prints every vehicle in the Fleet
//Throws an exception if given stream is corrupted
///////////////////////////////////////////////////////////////////////////
void Fleet::Print(std::ostream& ost) const
{
	if (!ost.good())
	{
		throw std::string("Stream Error");
	}
	else
	{
		for (auto const& v : mFleet)
		{
			v->Print(ost);
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//Private help function
//Searches for a vehicle with a given license plate.
//returns a const iterator to the place stored if found.
//returns mFleet.cend() if it isn´t found
///////////////////////////////////////////////////////////////////////////
FleetCont::const_iterator Fleet::FindLP(std::string const& l) const
{
	return std::find_if(mFleet.cbegin(), mFleet.cend(), [&l](Vehicle::SPtr const& ptr) { return l == ptr->GetLicensePlate(); });
}

//void Fleet::Copy(Fleet const& f)
//{
//	std::for_each(f.mFleet.cbegin(), f.mFleet.cend(), [this](auto v) {mFleet.push_back(v); });
//}

///////////////////////////////////////////////////////////////////////////
//operator<< overloading. Calls Print fouction of Fleet
///////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& ost, Fleet const& f)
{
	f.Print(ost);
	return ost;
}
