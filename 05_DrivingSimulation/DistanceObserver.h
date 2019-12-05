#ifndef DISTANCE_OBSERVER_H
#define DISTANCE_OBSERVER_H

#include "Object.h"
#include "DisplayObserver.h"

class DistanceObserver : public Object, public DisplayObserver{
public:
	using SPtr = std::shared_ptr<DistanceObserver>;
	void Update() override;
private:
	size_t mDistance;
};

#endif
