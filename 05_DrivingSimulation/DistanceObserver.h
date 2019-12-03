#ifndef DISTANCE_OBSERVER_H
#define DISTANCE_OBSERVER_H

#include "Object.h"
#include "DisplayObserver.h"

class DistanceObserver : public Object, DisplayObserver{
public:
	void Update() override;
private:
	size_t mDistance;
};

#endif
