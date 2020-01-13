///////////////////////////////////////////////////////////////////////////
// Workfile :		CmdFactory.cpp
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Implementation of Factory for Commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "CmdFactory.h"

Forward::UPtr CmdFactory::CreateForward(Robot::SPtr robot, int const & distance)
{
	return std::make_unique<Forward>(robot,distance);
}

TurnLeft::UPtr CmdFactory::CreateTurnLeft(Robot::SPtr robot)
{
	return std::make_unique<TurnLeft>(robot);
}

TurnRight::UPtr CmdFactory::CreateTurnRight(Robot::SPtr robot)
{
	return std::make_unique<TurnRight>(robot);
}
