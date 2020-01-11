///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			11-January2020
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Hexapod.h"
#include "WheelRobot.h"
#include "CleaningRobot.h"

int main() {



	Hexapod hexy(std::make_pair(100,100), "Hexy", Direction::NORTH);
	WheelRobot wheely(std::make_pair(0, 0), "Wheely", Direction::EAST);
	CleaningRobot cleany(std::make_pair(-130, 270), "Cleany", Direction::SOUTH);

	hexy.Info(std::cout);
	wheely.Info(std::cout);
	cleany.Info(std::cout);

	Hexapod pody(std::make_pair(0,50),"Pody", Direction::WEST);
	std::cout << std::endl;
	pody.Info(std::cout);

	return 0;
}