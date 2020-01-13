///////////////////////////////////////////////////////////////////////////
// Workfile :		Client.h
// Author :			Marc Haunschmied
// Date :			13-January-2020
// Description :	Tests all robot functions
// Revision :
///////////////////////////////////////////////////////////////////////////

#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "Object.h"
#include "Robot.h"

class Client : public Object {
private:
	std::list<Robot::SPtr> mRobots;
public:
	void TestRobot();
};

#endif
