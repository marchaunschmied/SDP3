///////////////////////////////////////////////////////////////////////////
// Workfile :		MacroMovement.cpp
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Executes several command at once
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <string>
#include "MacroMovement.h"

///////////////////////////////////////////////////////////////////////////
//Executes every Command in the list
///////////////////////////////////////////////////////////////////////////
void MacroMovement::Execute()
{
	for (auto const& cmd : mCommands)
	{
		cmd->Execute();
	}
}

///////////////////////////////////////////////////////////////////////////
//Undoes every Command in the list
///////////////////////////////////////////////////////////////////////////
void MacroMovement::Undo()
{
	//Undo all Commands in reversed order to get right result
	std::for_each(mCommands.crbegin(), mCommands.crend(), 
				  [](auto const& cmd) {cmd->Undo(); });
}


///////////////////////////////////////////////////////////////////////////
//Adds a Command to the MacroMovement
///////////////////////////////////////////////////////////////////////////
void MacroMovement::AddCmd(ICommand::SPtr cmd)
{
	//don't add a nullpointer
	if (cmd == nullptr)
	{
		throw std::string("Nullpointer in MacroMovement::AddCmd");
	}
	else
	{
		mCommands.emplace_back(cmd);
	}
}