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
	if (!mExecuted)
	{
		//save previous Direction for Undo
		mPrevDir = mRobot->GetDirection();
		//indicate that this command is already executed
		mExecuted = true;

		//calculate new direction
		int newTurn = (mPrevDir + DoTurn()) % DIRECTION_SIZE;
		//% operator does not work with negative values, you need to add
		//the divison factor 
		if (newTurn < 0) {
			newTurn += DIRECTION_SIZE;
		}
		//cast new direction, "%" ensures the values are in the right range
		Direction newDir = static_cast<Direction>(newTurn);

		mRobot->SetDirection(newDir);
	}
}


///////////////////////////////////////////////////////////////////////////
//Reset to previous Direction
///////////////////////////////////////////////////////////////////////////
void Turn::Undo()
{
	if (mExecuted)
	{
		mRobot->SetDirection(mPrevDir);
		mExecuted = false;
	}
	
}
///////////////////////////////////////////////////////////////////////////
//CTor forwards Robot to Command
///////////////////////////////////////////////////////////////////////////
Turn::Turn(Robot::SPtr robot): Command{robot}
{
}
