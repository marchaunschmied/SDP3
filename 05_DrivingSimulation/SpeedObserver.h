#ifndef SPEED_OBSERVER_H
#define SPEED_OBSERVER_H

#include "Object.h"
#include "DisplayObserver.h"

class SpeedObserver : public Object, public DisplayObserver{
	void Update() override;
};

#endif
