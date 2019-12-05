///////////////////////////////////////////////////////////////////////////
// Workfile :		DistanceObserver.cpp
// Author :			Marc Haunschmied
// Date :			03-December-2019
// Description :	Observer object for Digital Display
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <memory.h>
#include "DistanceObserver.h"
#include "WindowsDisplay.h"

DistanceObserver::DistanceObserver(std::shared_ptr<Car> pCar) {
	mDigDisp = std::make_shared<DigitalDisplay>();
	mCar = std::weak_ptr(pCar);
	mDistance = 0;
}

void DistanceObserver::Update() {
	mDistance += mCar.lock()->GetCurrentSpeed() * 500;
	mDigDisp->SendValue(mDistance);
}