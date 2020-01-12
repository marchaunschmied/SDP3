///////////////////////////////////////////////////////////////////////////
// Workfile :		TurnLeft.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Concrete Turn command
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef TURNLEFT_H
#define TURNLEFT_H

#include "Turn.h"

class TurnLeft : public Turn {
public:
	using SPtr = std::shared_ptr<TurnLeft>;
	TurnLeft(Robot::SPtr robot);
protected:
	virtual int DoTurn() const override;
};

#endif
