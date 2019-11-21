#ifndef JAVA_SYMBOL_FACTORY_H
#define JAVA_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "JavaType.h"
#include "JavaVariable.h"

class JavaSymbolFactory : public SymbolFactory {
public:
	Type::SPtr CreateType(std::string const& typeName) override;
	Variable::UPtr CreateVariable(std::string const& typeName) override;
};

#endif