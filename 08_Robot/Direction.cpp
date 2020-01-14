///////////////////////////////////////////////////////////////////////////
// Workfile :		Direction.cpp
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Facing direction
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Direction.h"

//cpp does not allow enum to string conversion. Therefore this
//switch statement is needed
std::ostream& operator<<(std::ostream& ost, Direction const& dir)
{
	switch (dir) {
	case Direction::NORTH:
		ost << "NORTH";
		break;
	case Direction::EAST:
		ost << "EAST";
		break;
	case Direction::SOUTH:
		ost << "SOUTH";
		break;
	case Direction::WEST:
		ost << "WEST";
		break;
	}
	return ost;
}
