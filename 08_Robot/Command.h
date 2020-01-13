///////////////////////////////////////////////////////////////////////////
// Workfile :		Command.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Base class for commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef COMMAND_H
#define COMMAND_H

#include "Object.h"
#include "ICommand.h"
#include "Robot.h"


class Command : public ICommand, public Object {
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;

protected:
	Command(Robot::SPtr robot);
	Robot::SPtr mRobot;
	bool mExecuted = false;
	
};

#endif
