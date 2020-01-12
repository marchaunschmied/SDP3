///////////////////////////////////////////////////////////////////////////
// Workfile :		Turn.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Base class for all direction changing commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef TURN_H
#define TURN_H

#include "Command.h"
#include "Direction.h"

class Turn : public Command {
public:
	virtual void Execute() override;
	virtual void Undo() override;

protected:
	Turn(Robot::SPtr robot);

	virtual int DoTurn() const;

private:
	Direction mPrevDir;

};
#endif
