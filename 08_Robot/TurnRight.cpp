///////////////////////////////////////////////////////////////////////////
// Workfile :		TurnRight.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Concrete Turn command
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "TurnRight.h"

///////////////////////////////////////////////////////////////////////////
//CTor forwards Robot to Turn
///////////////////////////////////////////////////////////////////////////
TurnRight::TurnRight(Robot::SPtr robot): Turn{robot}
{
}

///////////////////////////////////////////////////////////////////////////
//Provides Offset to Turn
///////////////////////////////////////////////////////////////////////////
int TurnRight::DoTurn() const
{
	return 5;
}
