///////////////////////////////////////////////////////////////////////////
// Workfile :		Client.cpp
// Author :			Marc Haunschmied
// Date :			13-January-2020
// Description :	Tests all robot functions
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <algorithm>
#include "Client.h"


#include "Hexapod.h"
#include "WheelRobot.h"
#include "CleaningRobot.h"
#include "CmdFactory.h"
#include "MacroMovement.h"
#include "ControllUnit.h"

void Client::AddRobot(Robot::SPtr robot){
	if (robot != nullptr) {
		mRobots.push_back(robot);
	}
}

void Client::Print() const{
	for (Robot::SPtr r : mRobots) {
		r->Info(std::cout);
	}
}
