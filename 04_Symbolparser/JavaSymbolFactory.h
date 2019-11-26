///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaSymbolFactory.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Returns a Java Symbol
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef JAVA_SYMBOL_FACTORY_H
#define JAVA_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "JavaType.h"
#include "JavaVariable.h"
#include "SingletonBase.h"
#include <iostream>
#include <memory>

class JavaSymbolFactory : public SymbolFactory, public SingletonBase<JavaSymbolFactory>{

public:
	Type::SPtr CreateType(std::string const& typeName) override;
	Variable::UPtr CreateVariable(std::string const& typeName, Type::SPtr type) override;


private:
	friend class SingletonBase<JavaSymbolFactory>;
	JavaSymbolFactory();
};

#endif