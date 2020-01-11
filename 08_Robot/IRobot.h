///////////////////////////////////////////////////////////////////////////
// Workfile :		IRobot.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Interface for a robot class
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef I_ROBOT_H
#define I_ROBOT_H

#include <iostream>

class IRobot {
public:
	virtual void Info(std::ostream& os) const = 0;
	virtual ~IRobot();
};
#endif
