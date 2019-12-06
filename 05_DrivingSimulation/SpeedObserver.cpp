///////////////////////////////////////////////////////////////////////////
// Workfile :		SpeedObserver.cpp
// Author :			Marc Haunschmied
// Date :			03-December-2019
// Description :	Observer object for Analog Display
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "SpeedObserver.h"

static double const MS_TO_KMH_FACTOR = 3.6;

SpeedObserver::SpeedObserver(Car::SPtr pCar) {
	mAnaDisp = std::make_shared<AnalogDisplay>();
	mCar = std::weak_ptr(pCar);
}

void SpeedObserver::Update() {
	size_t speed = mCar.lock()->GetCurrentSpeed() * MS_TO_KMH_FACTOR;
	mAnaDisp->SendValue(speed);
	std::cout << "Speed: " << speed << std::endl;
}