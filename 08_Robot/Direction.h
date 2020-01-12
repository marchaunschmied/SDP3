///////////////////////////////////////////////////////////////////////////
// Workfile :		Direction.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Facing direction
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

const size_t DIRECTION_SIZE = 4;

enum Direction {
	NORTH,	//0
	EAST,	//1
	SOUTH,	//2
	WEST	//3

};

std::ostream& operator<<(std::ostream& ost, Direction const& dir);

#endif
