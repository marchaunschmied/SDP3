///////////////////////////////////////////////////////////////////////////
// Workfile :		DistanceObserver.h
// Author :			Marc Haunschmied
// Date :			9-December-2019
// Description :	Observer to send distance data from an vehicle to a
//					digitial display
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef DISTANCE_OBSERVER_H
#define DISTANCE_OBSERVER_H

#include "Object.h"
#include "DisplayObserver.h"
#include "WindowsDisplay.h"
#include "Car.h"

class DistanceObserver : public Object, public DisplayObserver{
public:

	using SPtr = std::shared_ptr<DistanceObserver>;
	DistanceObserver(Car::SPtr pCar);

	void Update() override;
private:
	double mDistance;

	WindowsDisplay::SPtr mDigDisp;
	std::weak_ptr<Car> mCar;
};

#endif
