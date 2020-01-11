///////////////////////////////////////////////////////////////////////////
// Workfile :		CleaningRobot.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	This robot is your personal slave and cleans all your 
//					dirty rooms and floors
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef CLEANING_ROBOT_H
#define CLEANING_ROBOT_H

#include "Robot.h"
class CleaningRobot : public Robot{
public:
	std::string GetRobotType() const override;
	CleaningRobot(Position const& pos = std::make_pair(0, 0), std::string const& name = "", Direction const& dir = Direction::NORTH);
};

#endif
