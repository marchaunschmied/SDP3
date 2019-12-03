#ifndef DISPLAY_OBSERVER_H
#define DISPLAY_OBSERVER_H

#include <memory>

class DisplayObserver {
public:
	using SPtr = std::shared_ptr<DisplayObserver>;
	virtual void Update() = 0;
};

#endif
