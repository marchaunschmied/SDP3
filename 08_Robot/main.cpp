///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			11-January2020
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <memory>

#include "vld.h"
#include "Client.h"
#include "Hexapod.h"
#include "WheelRobot.h"
#include "CleaningRobot.h"
#include "CmdFactory.h"
#include "MacroMovement.h"
#include "ControllUnit.h"


using namespace std;

int main() {

	try
	{
		Client tester;

		tester.Print();

		CmdFactory fact;

		Hexapod::SPtr hexy = std::make_shared<Hexapod>(std::make_pair(100, 100), "Hexy", Direction::NORTH);
		WheelRobot::SPtr wheely = std::make_shared<WheelRobot>(std::make_pair(0, 0), "Wheely", Direction::EAST);
		CleaningRobot::SPtr cleany = std::make_shared<CleaningRobot>(std::make_pair(-130, 270), "Cleany", Direction::SOUTH);

		//test client
		tester.AddRobot(hexy);
		tester.AddRobot(wheely);
		tester.AddRobot(cleany);

		tester.Print();

		//make five turns counter clock wise
		std::cout << std::endl << "------------------------------------" << std::endl;
		std::cout << "Test ControllUnit (5 turns left: " << std::endl << std::endl;
		ControllUnit cont;
		cont.AddCommand(fact.CreateTurnLeft(hexy));
		cont.AddCommand(fact.CreateTurnLeft(hexy));
		cont.AddCommand(fact.CreateTurnLeft(hexy));
		cont.AddCommand(fact.CreateTurnLeft(hexy));
		cont.AddCommand(fact.CreateTurnLeft(hexy));

		cont.Start();

		hexy->Info(std::cout);
		std::cout << std::endl;

		cont.Undo(1);
		hexy->Info(std::cout);
		std::cout << std::endl;

		cont.Undo(1);
		hexy->Info(std::cout);
		std::cout << std::endl;

		cont.Reset();
		cont.Undo(5);
		hexy->Info(std::cout);
		std::cout << std::endl;

		std::cout << std::endl << "------------------------------------" << std::endl;
		std::cout << "Test ControllUnit and new Robot:" << std::endl;
		//new hexapod
		Hexapod::SPtr pody = std::make_shared<Hexapod>(std::make_pair(0, 50), "Pody", Direction::WEST);
		std::cout << std::endl;
		pody->Info(std::cout);


		ControllUnit podyControll;
		//move 50 to left 2x 
		cont.AddCommand(fact.CreateForward(pody, 50));
		cont.AddCommand(fact.CreateForward(pody, 50));

		//turn down
		cont.AddCommand(fact.CreateTurnLeft(pody));
		//move 100 down
		cont.AddCommand(fact.CreateForward(pody, 100));

		cont.Start();

		std::cout << std::endl << "100 left, turn down and 100 south:" << std::endl;
		pody->Info(std::cout);

		std::cout << std::endl << "------------------------------------" << std::endl;
		std::cout << "Test MacroCommand:" << std::endl;

		//reset controll units for both hexapods
		cont.Reset();
		podyControll.Reset();

		MacroMovement macro;
		macro.AddCmd(fact.CreateForward(pody, 50));
		macro.AddCmd(fact.CreateTurnLeft(pody));
		macro.AddCmd(fact.CreateTurnLeft(pody));
		macro.AddCmd(fact.CreateForward(pody, 350));
		macro.Execute();

		std::cout << std::endl << "Go 50 forward, turn around and go 350 back:" << std::endl;
		pody->Info(std::cout);

		macro.Undo();

		std::cout << std::endl << "Redo all actions:" << std::endl;
		pody->Info(std::cout);

		//execute macro again --> nothing happens because each command only works once
		macro.Execute();
		std::cout << std::endl << "Execute again(nothing happens):" << std::endl;
		pody->Info(std::cout);

		macro.Execute();
		std::cout << std::endl << "Execute again:" << std::endl;
		pody->Info(std::cout);

		std::cout << std::endl << "write to file:" << std::endl;
		std::ofstream file{ "Test.txt" };
		if (file.is_open()) {
			pody->Info(file);
		}
		else {
			std::cerr << "ERROR: in open File" << std::endl;
		}
		file.close();
		if (file.is_open()) {
			std::cerr << "ERROR: in closing File" << std::endl;
		}
		std::cout << std::endl << std::endl;


		std::cout << std::endl << "------------------------------------" << std::endl;
		std::cout << "Test MacroCommand in ControllUnit:" << std::endl;



		//MacroMovement macro1;
		MacroMovement macro1;
		macro1.AddCmd(fact.CreateForward(wheely, 50));
		macro1.AddCmd(fact.CreateTurnRight(wheely));
		macro1.AddCmd(fact.CreateForward(wheely, 100));

		//create unique ptr on macro movement
		//move is needed because, unique_ptr can not be copied
		MacroMovement::UPtr test = std::make_unique<MacroMovement>(std::move(macro1));

		ControllUnit wheelyControll;
		wheelyControll.AddCommand(std::move(test));

		std::cout << std::endl << "Go 50 east, turn right and 100 south:" << std::endl;
		wheely->Info(std::cout);
		std::cout << std::endl;
		wheelyControll.Start();
		std::cout << std::endl;
		wheely->Info(std::cout);
	}
	catch (exception const& ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}
	catch (std::string const& s)
	{
		cerr << s << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception" << endl;
		return 1;
	}
	return 0;
} 