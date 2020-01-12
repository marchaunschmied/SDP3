///////////////////////////////////////////////////////////////////////////
// Workfile :		CmdFactory.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Factory for Commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef CMDFACTORY_H
#define CMDFACTORY_H

#include "Object.h"
#include "Forward.h"
#include "TurnLeft.h"
#include "TurnRight.h"

class CmdFactory : public Object {
public:
	Forward::SPtr CreateForward(Robot::SPtr robot);
	TurnLeft::SPtr CreateTurnLeft(Robot::SPtr robot);
	TurnRight::SPtr CreateTurnRight(Robot::SPtr robot);
};

#endif
