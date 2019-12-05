///////////////////////////////////////////////////////////////////////////
// Workfile :		SpeedObserver.cpp
// Author :			Marc Haunschmied
// Date :			03-December-2019
// Description :	Observer object for Analog Display
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "SpeedObserver.h"

SpeedObserver::SpeedObserver(std::shared_ptr<Car> pCar) {
	mAnaDisp = std::make_shared<AnalogDisplay>();
	mCar = std::weak_ptr(pCar);
}

void SpeedObserver::Update() {
	size_t speed = mCar.lock()->GetCurrentSpeed() * 3.6;
	mAnaDisp->SendValue(speed);
}