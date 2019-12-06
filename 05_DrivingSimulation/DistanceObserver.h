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
