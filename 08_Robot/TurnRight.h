///////////////////////////////////////////////////////////////////////////
// Workfile :		TurnRight.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Concrete Turn command
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef TURNRIGHT_H
#define TURNRIGHT_H

#include "Turn.h"

class TurnRight : public Turn {
public:
	using SPtr = std::shared_ptr<TurnRight>;
	TurnRight(Robot::SPtr robot);
protected:
	virtual int DoTurn() const override;
};

#endif
