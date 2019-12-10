///////////////////////////////////////////////////////////////////////////
// Workfile :		Vehicle.h
// Author :			Markus Riegler
// Date :			05-December-2019
// Description :	Header of class Vehicle
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef VEHICLE_H
#define VEHICLE_H

#include <memory>
#include <vector>
#include <algorithm>
#include <string>

#include "Object.h"
#include "DisplayObserver.h"


class Vehicle : Object {
public:
	//typedefs
	typedef std::shared_ptr<Vehicle> SPtr;
	typedef std::vector<DisplayObserver::SPtr> ObsCont;

	//Add & Remove Observers from vector
	void Attach(DisplayObserver::SPtr const& obs);
	void Detach(DisplayObserver::SPtr const& obs);

protected:
	//abstract class protected CTor
	Vehicle() = default;
	//Notifies all Observers
	void Notify();
private:
	//Container for observers
	ObsCont mObservers;

	//Help functions
	//Searches Container for a specific Observer
	ObsCont::const_iterator Contained(DisplayObserver::SPtr const& obs) const;
};
#endif
