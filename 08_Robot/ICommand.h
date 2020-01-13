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
	using UPtr = std::unique_ptr<ICommand>;
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual ~ICommand() = default;
protected:
	ICommand() = default;
};
#endif
