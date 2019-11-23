///////////////////////////////////////////////////////////////////////////
// Workfile :		SymbolFactory.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef SYMBOL_FACTORY_H
#define SYMBOL_FACTORY_H

#include "Object.h"
#include "Type.h"
#include "Variable.h"
#include "SingletonBase.h"


class SymbolFactory : public Object {
public:	
	virtual Type::SPtr CreateType(std::string const& typeName) = 0;
	virtual Variable::UPtr CreateVariable(std::string const& typeName, Type::SPtr type) = 0;

	std::string GetTypeFilename() const;
	std::string GetVariableFilename() const;
	
protected:
	SymbolFactory(std::string const& filenameT, std::string const& filenameV);
	SymbolFactory(SymbolFactory const& sym) = delete;
	SymbolFactory& operator=(SymbolFactory const& sym) = delete;

private:
	std::string mTypeFileName;
	std::string mVariableFileName;
};

#endif