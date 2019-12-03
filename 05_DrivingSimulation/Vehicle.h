#ifndef VEHICLE_H
#define VEHICLE_H

#include <memory>
#include <vector>

#include "Object.h"
#include "DisplayObserver.h"


class Vehicle : Object {
public:
	using SPtr = std::shared_ptr<DisplayObserver>;

	void Attach();
	void Dettach();
protected:
	void Notify();
private:
	std::vector<SPtr> mObsever;
};
#endif
