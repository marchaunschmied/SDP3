#ifndef SYMBOL_FACTORY_H
#define SYMBOL_FACTORY_H

#include "Object.h"
#include "Type.h"
#include "Variable.h"

class SymbolFactory : public Object {
private:
	std::string mTypeFileName;
	std::string mVariableFileName;
	std::unique_ptr<SymbolFactory> mInstance;
	
	SymbolFactory() = default;

public:

	virtual std::unique_ptr<SymbolFactory> GetInstance() = 0;

	virtual Type * CreateType(std::string const& typeName) = 0;
	virtual Variable * CreateVariable(std::string const& typeName) = 0;
};

#endif