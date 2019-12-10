///////////////////////////////////////////////////////////////////////////
// Workfile :		DistanceObserver.cpp
// Author :			Marc Haunschmied
// Date :			03-December-2019
// Description :	Observer object for Digital Display
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory.h>
#include "DistanceObserver.h"
#include "WindowsDisplay.h"

static double const INTERVAL = 0.5; //time in s

DistanceObserver::DistanceObserver(Car::SPtr pCar) {
	mDigDisp = std::make_shared<DigitalDisplay>();
	mCar = std::weak_ptr(pCar);
	mDistance = 0;
}

void DistanceObserver::Update() {
	mDistance += mCar.lock()->GetCurrentSpeed() * INTERVAL;
	mDigDisp->SendValue(mDistance);
	std::cout << "Distance: " << mDistance << std::endl;
}