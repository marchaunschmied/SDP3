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

	Hexapod::SPtr hexy = make_shared<Hexapod>(make_pair(100,100), "Hexy", Direction::NORTH);
	WheelRobot::SPtr wheely = make_shared<WheelRobot>(make_pair(0, 0), "Wheely", Direction::EAST);
	CleaningRobot::SPtr cleany = make_shared<CleaningRobot>(make_pair(-130, 270), "Cleany", Direction::SOUTH);

	hexy->Info(cout);
	wheely->Info(cout);
	cleany->Info(cout);
	
	//make four turns counter clock wise

	ICommand::SPtr hexyDoLeft = fact.CreateTurnLeft(hexy);
	ICommand::SPtr hexyDoRight = fact.CreateTurnRight(hexy);
	hexyDoLeft->Execute();
	cout << endl;
	hexy->Info(cout);
	
	hexyDoLeft->Execute();
	cout << endl;
	hexy->Info(cout);

	hexyDoLeft->Execute();
	cout << endl;
	hexy->Info(cout);

	hexyDoLeft->Execute();
	cout << endl;
	hexy->Info(cout);

	//turn one back
	hexyDoRight->Execute();
	cout << endl;
	hexy->Info(cout);


	cout << endl << "------------------------------------" << endl;
	//new hexapod
	Hexapod::SPtr pody = make_shared<Hexapod>(std::make_pair(0, 50), "Pody", Direction::WEST);
	cout << endl;
	pody->Info(cout);

	return 0;
} 