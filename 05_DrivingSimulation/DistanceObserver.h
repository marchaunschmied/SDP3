#ifndef DISTANCE_OBSERVER_H
#define DISTANCE_OBSERVER_H

#include "Object.h"
#include "DisplayObserver.h"
#include "WindowsDisplay.h"
#include "Car.h"

class DistanceObserver : public Object, DisplayObserver{
public:
	DistanceObserver(std::shared_ptr<Car> pCar);
	void Update() override;
private:
	size_t mDistance;

	WindowsDisplay::SPtr mDigDisp;
	std::weak_ptr<Car> mCar;
};

#endif
