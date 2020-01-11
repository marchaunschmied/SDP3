///////////////////////////////////////////////////////////////////////////
// Workfile :		Robot.cpp
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Abstract robot class
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "Robot.h"

void Robot::Info(std::ostream& os) const {
	if (os.good()) {
		os << GetRobotType() << ":\t " << mName << ", Pos(" << mPos.first << "," << mPos.second << "), Direction(" << mDir << ")" << std::endl;
	}
}

Robot::~Robot(){
}


Robot::Robot(Position const& pos, std::string const& name, Direction const& dir) : mPos(pos), mName(name), mDir(dir){
}


void Robot::SetPos(Position const& pos){
	mPos = pos;
}

void Robot::SetName(std::string const& name){
	mName = name;
}

void Robot::SetDirection(Direction const& dir){
	mDir = dir;
}
