#ifndef SYMBOL_FACTORY_H
#define SYMBOL_FACTORY_H

#include "Object.h"
#include "Type.h"
#include "Variable.h"

class SymbolFactory : public Object {
public:
	typedef std::shared_ptr<SymbolFactory> SPtr;
	virtual SymbolFactory::SPtr GetInstance() = 0;

	virtual Type::SPtr CreateType(std::string const& typeName) = 0;
	virtual Variable::UPtr CreateVariable(std::string const& typeName) = 0;

	std::string GetTypeFilename() const;
	std::string GetVariableFilename() const;

private:
	std::string mTypeFileName;
	std::string mVariableFileName;
	SymbolFactory::SPtr mInstance;
	
	SymbolFactory() = default;
};

#endif