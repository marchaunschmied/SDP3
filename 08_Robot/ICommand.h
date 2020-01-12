///////////////////////////////////////////////////////////////////////////
// Workfile :		ICommand.h
// Author :			Markus Riegler
// Date :			12-January-2020
// Description :	Interface for commands
// Revision :
///////////////////////////////////////////////////////////////////////////

#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <memory>

class ICommand {
public:
	using SPtr = std::shared_ptr<ICommand>;
	virtual void Execute() = 0;
	virtual void Undo() = 0;
protected:
	ICommand() = default;
};
#endif
