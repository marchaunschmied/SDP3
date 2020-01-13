///////////////////////////////////////////////////////////////////////////
// Workfile :		Client.cpp
// Author :			Marc Haunschmied
// Date :			13-January-2020
// Description :	Tests all robot functions
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include "Client.h"


#include "Hexapod.h"
#include "WheelRobot.h"
#include "CleaningRobot.h"
#include "CmdFactory.h"
#include "MacroMovement.h"
#include "ControllUnit.h"

void Client::TestRobot(){
	
	/*mRobots.push_back(
	Hexapod::SPtr hexy = std::make_shared<Hexapod>(std::make_pair(100, 100), "Hexy", Direction::NORTH);
	WheelRobot::SPtr wheely = std::make_shared<WheelRobot>(std::make_pair(0, 0), "Wheely", Direction::EAST);
	CleaningRobot::SPtr cleany = std::make_shared<CleaningRobot>(std::make_pair(-130, 270), "Cleany", Direction::SOUTH);
	*/


}
