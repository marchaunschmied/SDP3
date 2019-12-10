///////////////////////////////////////////////////////////////////////////
// Workfile :		DisplayObserver.h
// Author :			Marc Haunschmied
// Date :			9-December-2019
// Description :	Observer for sending data to an external display
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef DISPLAY_OBSERVER_H
#define DISPLAY_OBSERVER_H

#include <memory>

class DisplayObserver {
public:
	using SPtr = std::shared_ptr<DisplayObserver>;
	virtual void Update() = 0;
	virtual ~DisplayObserver() = default;
protected:
	DisplayObserver() = default;
};

#endif
