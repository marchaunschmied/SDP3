///////////////////////////////////////////////////////////////////////////
// Workfile :		ControllUnit.cpp
// Author :			Markus Riegler
// Date :			13-January-2020
// Description :	Implementation of class ControllUnit
// Revision :
///////////////////////////////////////////////////////////////////////////
#include "ControllUnit.h"

///////////////////////////////////////////////////////////////////////////
//Adds a Command to command list
///////////////////////////////////////////////////////////////////////////
void ControllUnit::AddCommand(ICommand::UPtr cmd)
{
	if (cmd == nullptr)
	{
		throw std::string("Nullpointer in ControllUnit::AddCommand");
	}
	else
	{
		mDo.emplace(cmd.release());
	}
}

///////////////////////////////////////////////////////////////////////////
//starts execution of all commands in list
///////////////////////////////////////////////////////////////////////////
void ControllUnit::Start()
{
	while (!mDo.empty())
	{
		//Execute command
		mDo.front()->Execute();
		//save command to Undo list
		mUndo.emplace(mDo.front().release());
		//delete command from do list
		mDo.pop();
	}
}

///////////////////////////////////////////////////////////////////////////
//undo and removes specified count of commands
///////////////////////////////////////////////////////////////////////////
void ControllUnit::Undo(size_t const count)
{
	for (size_t i = 0; i < count; ++i)
	{
		if (!mUndo.empty())
		{
			mUndo.top()->Undo();
			mUndo.pop();
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//removes all commands
///////////////////////////////////////////////////////////////////////////
void ControllUnit::Reset()
{
	//create empty containers
	std::queue<ICommand::UPtr> emptyDo;
	std::stack<ICommand::UPtr> emptyUndo;
	//swap with empty containers
	mDo.swap(emptyDo);
	mUndo.swap(emptyUndo);
}
