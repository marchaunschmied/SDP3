///////////////////////////////////////////////////////////////////////////
// Workfile :		CmdFactory.cpp
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Implementation of Factory for Commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "CmdFactory.h"

Forward::SPtr CmdFactory::CreateForward(Robot::SPtr robot)
{
	return std::make_shared<Forward>(robot);
}

TurnLeft::SPtr CmdFactory::CreateTurnLeft(Robot::SPtr robot)
{
	return std::make_shared<TurnLeft>(robot);
}

TurnRight::SPtr CmdFactory::CreateTurnRight(Robot::SPtr robot)
{
	return std::make_shared<TurnRight>(robot);
}
