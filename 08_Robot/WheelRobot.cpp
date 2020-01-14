///////////////////////////////////////////////////////////////////////////
// Workfile :		WheelRobot.cpp
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Robot that drives on one wheel
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "WheelRobot.h"

std::string WheelRobot::GetRobotType() const{
	return "WheelRobot";
}

WheelRobot::WheelRobot(Position const& pos, std::string const& name, Direction const& dir) : Robot(pos, name, dir) {

}