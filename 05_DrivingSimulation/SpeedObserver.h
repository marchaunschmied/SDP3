///////////////////////////////////////////////////////////////////////////
// Workfile :		SpeedObserver.h
// Author :			Marc Haunschmied
// Date :			9-December-2019
// Description :	Observer for sending speed data to an analog display
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef SPEED_OBSERVER_H
#define SPEED_OBSERVER_H

#include <memory>

#include "Object.h"
#include "DisplayObserver.h"
#include "WindowsDisplay.h"
#include "Car.h"

class SpeedObserver : public Object, public DisplayObserver{
public:
	SpeedObserver(Car::SPtr pCar);
	void Update() override;
private:
	WindowsDisplay::SPtr mAnaDisp;
	std::weak_ptr<Car> mCar;
};

#endif
