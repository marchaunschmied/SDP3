///////////////////////////////////////////////////////////////////////////
// Workfile :		MacroMovement.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Executes several command at once
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef MACROMOVEMENT_H
#define MACROMOVEMENT_H

#include <list>
#include "Object.h"
#include "ICommand.h"

class MacroMovement : public ICommand, public Object {
public:
	virtual void Execute() override;
	virtual void Undo() override;

	void AddCmd(ICommand::SPtr cmd);

private:
	std::list<ICommand::SPtr> mCommands;
};
#endif
