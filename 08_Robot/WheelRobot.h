///////////////////////////////////////////////////////////////////////////
// Workfile :		WheelRobot.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Robot that drives on one wheel
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef WHEEL_ROBOT_H
#define WHEEL_ROBOT_H

#include "Robot.h"
class WheelRobot : public Robot{
public:
	std::string GetRobotType() const override;
	WheelRobot(Position const& pos = std::make_pair(0, 0), std::string const& name = "", Direction const& dir = Direction::NORTH);
};

#endif
