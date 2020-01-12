///////////////////////////////////////////////////////////////////////////
// Workfile :		Command.cpp
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Implementation of base class for commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "Command.h"

Command::Command(Robot::SPtr robot)
{
	//don't allow Command without a valid Robot to control
	if (robot == nullptr)
	{
		throw std::string("Nullpointer in CTor of Command");
	}
	else
	{
		mRobot = robot;
	}
}
