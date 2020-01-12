///////////////////////////////////////////////////////////////////////////
// Workfile :		Turn.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Implementation of ase class for all 
//					direction changing commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "Turn.h"


///////////////////////////////////////////////////////////////////////////
//Changes the Direction of the Robot
///////////////////////////////////////////////////////////////////////////
void Turn::Execute()
{
	//save previous Direction for Undo
	mPrevDir = mRobot->GetDirection();

	Direction newDir = (mPrevDir + DoTurn()) % 4;
}


///////////////////////////////////////////////////////////////////////////
//Reset to previous Direction
///////////////////////////////////////////////////////////////////////////
void Turn::Undo()
{
	mRobot->SetDirection(mPrevDir);
}
///////////////////////////////////////////////////////////////////////////
//CTor forwards Robot to Command
///////////////////////////////////////////////////////////////////////////
Turn::Turn(Robot::SPtr robot): Command{robot}
{
}