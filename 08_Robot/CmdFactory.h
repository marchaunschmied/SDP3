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
	Forward::UPtr CreateForward(Robot::SPtr robot, int const & distance);
	TurnLeft::UPtr CreateTurnLeft(Robot::SPtr robot);
	TurnRight::UPtr CreateTurnRight(Robot::SPtr robot);
};

#endif
