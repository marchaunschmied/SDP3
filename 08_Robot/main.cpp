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
#include "ControllUnit.h"

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
	ControllUnit cont;
	cont.AddCommand(fact.CreateTurnLeft(hexy));
	cont.AddCommand(fact.CreateTurnLeft(hexy));
	cont.AddCommand(fact.CreateTurnLeft(hexy));
	cont.AddCommand(fact.CreateTurnLeft(hexy));
	cont.AddCommand(fact.CreateTurnLeft(hexy));

	cont.Start();

	hexy->Info(cout);
	cout << endl;

	cont.Undo(1);
	hexy->Info(cout);
	cout << endl;

	cont.Undo(1);
	hexy->Info(cout);
	cout << endl;

	cont.Reset();
	cont.Undo(5);
	hexy->Info(cout);
	cout << endl;




	cout << endl << "------------------------------------" << endl;
	//new hexapod
	Hexapod::SPtr pody = make_shared<Hexapod>(std::make_pair(0, 50), "Pody", Direction::WEST);
	cout << endl;
	pody->Info(cout);

	ICommand::UPtr podyDoForward = fact.CreateForward(pody, 50);


	podyDoForward->Execute();
	cout << endl << "Move 50 to left" <<  endl;
	pody->Info(cout);


	podyDoForward->Execute();
	cout << endl << "Move 50 to left" << endl;
	pody->Info(cout);

	ICommand::UPtr podyDoLeft = fact.CreateTurnLeft(pody);

	podyDoLeft->Execute();
	cout << endl << "Turn down" << endl;
	pody->Info(cout);

	podyDoForward->Execute();
	cout << endl << "Move 50 down" << endl;
	pody->Info(cout);


	return 0;
} 