///////////////////////////////////////////////////////////////////////////
// Workfile :		Hexapod.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Robot with 6 legs, looks like a spider
// Revision :
///////////////////////////////////////////////////////////////////////////



#ifndef HEXAPOD_H
#define HEXAPOD_H

#include "Robot.h"
class Hexapod :	public Robot{
public:
	std::string GetRobotType() const override;
	Hexapod(Position const& pos = std::make_pair(0, 0), std::string const& name = "", Direction const& dir = Direction::NORTH);

	
};

#endif
