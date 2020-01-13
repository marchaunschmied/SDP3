///////////////////////////////////////////////////////////////////////////
// Workfile :		ControllUnit.h
// Author :			Markus Riegler
// Date :			13-January-2020
// Description :	Factory for Commands
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef CONTROLLUNIT_H
#define CONTROLLUNIT_H

#include <queue>
#include <stack>
#include "Object.h"
#include "Command.h"

class ControllUnit : public Object {
public:
	void AddCommand(/*Command*/); //adds a command to command list
	void Start(); //starts execution of all commands in list
	void Undo(size_t const count); //undo and removes specified count of commands
	void Reset(); //removes all commands
private:
	std::queue<ICommand::UPtr> mDo;
	std::stack<ICommand::UPtr> mUndo;

};
#endif
