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
#include "CmdFactory.h"
#include "MacroMovement.h"

using namespace std;

int main() {

	CmdFactory fact;

	Hexapod hexy(std::make_pair(100,100), "Hexy", Direction::NORTH);
	WheelRobot wheely(std::make_pair(0, 0), "Wheely", Direction::EAST);
	CleaningRobot cleany(std::make_pair(-130, 270), "Cleany", Direction::SOUTH);

	hexy.Info(std::cout);
	wheely.Info(std::cout);
	cleany.Info(std::cout);

	Hexapod pody(std::make_pair(0,50),"Pody", Direction::WEST);
	std::cout << std::endl;
	pody.Info(std::cout);

	ICommand::SPtr cmd = fact.CreateTurnLeft(make_shared<Hexapod>(hexy));
	cmd->Execute();
	cout << endl;
	hexy.Info(cout);

	return 0;
}