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
	typedef std::shared_ptr<DisplayObserver> SPtr;
	typedef std::vector<Vehicle::SPtr> ObsCont;

	void Attach(DisplayObserver::SPtr obs);
	void Detach(DisplayObserver::SPtr obs);

protected:
	Vehicle() = default;
	void Notify();
private:
	
	ObsCont mObservers;

	//Help functions
	ObsCont::const_iterator Contained(DisplayObserver::SPtr const& obs) const;
};
#endif
