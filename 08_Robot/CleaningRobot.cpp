///////////////////////////////////////////////////////////////////////////
// Workfile :		CleaningRobot.cpp
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	This robot is your personal slave and cleans all your 
//					dirty rooms and floors
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "CleaningRobot.h"

std::string CleaningRobot::GetRobotType() const{
	return "CleaningRobot";
}
CleaningRobot::CleaningRobot(Position const& pos, std::string const& name, Direction const& dir) : Robot(pos, name, dir) {

}