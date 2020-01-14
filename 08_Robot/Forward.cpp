///////////////////////////////////////////////////////////////////////////
// Workfile :		Forward.cpp
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Implementation of forward movement command
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Forward.h"

std::string const WARNING_NEGATIVE = "WARNING: Distance has to be positive. 0 is used instead!";

///////////////////////////////////////////////////////////////////////////
//Executes the forward movement with the current direction and saves
//previous position for Undo()
///////////////////////////////////////////////////////////////////////////
void Forward::Execute()
{
	if (!mExecuted)
	{
		//save the position before movement
		mPrevPos = mRobot->GetPosition();
		//indicate that this command is already executed
		mExecuted = true;

		//Change Position according to current Direction
		Direction dir = mRobot->GetDirection();
		Position movePos = mPrevPos;
		switch (dir) {
		case Direction::NORTH:
			//move up on y-axis
			movePos.second += mDistance;
			break;
		case Direction::EAST:
			//move right on x-axis
			movePos.first += mDistance;
			break;
		case Direction::SOUTH:
			//move down on y-axis
			movePos.second -= mDistance;
			break;
		case Direction::WEST:
			//move left on x-axis
			movePos.first -= mDistance;
			break;
		}
		mRobot->SetPos(movePos);
	}
}

///////////////////////////////////////////////////////////////////////////
//Reset Robot to previous Position before movement
///////////////////////////////////////////////////////////////////////////
void Forward::Undo()
{
	if (mExecuted)
	{
		mRobot->SetPos(mPrevPos);
		mExecuted = false;
	}
	
}

///////////////////////////////////////////////////////////////////////////
//CTor sets Distance and forwards Robot to Command
///////////////////////////////////////////////////////////////////////////
Forward::Forward(Robot::SPtr robot, int distance) : Command{robot}
{
	if (distance < 0)
	{
		std::cerr << WARNING_NEGATIVE << std::endl;
		mDistance = 0;
	}
	else
	{
		mDistance = distance;
	}
}
