///////////////////////////////////////////////////////////////////////////
// Workfile :		Forward.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Movement command
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef FORWARD_H
#define FORWARD_H

#include "Command.h"

class Forward : public Command {
public:
	using SPtr = std::shared_ptr<Forward>;

	virtual void Execute() override;
	virtual void Undo() override;

	Forward(Robot::SPtr robot);

private:
	Position mPrevPos;
};

#endif
