///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaSymbolFactory.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Returns a Java Symbol
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "JavaSymbolFactory.h"
#include <memory>

JavaSymbolFactory::JavaSymbolFactory() : SymbolFactory("JavaTypes.sym", "JavaVars.sym") {};


Type::SPtr JavaSymbolFactory::CreateType(std::string const& typeName)  {
	return std::make_shared<JavaType>(typeName);
}
Variable::UPtr JavaSymbolFactory::CreateVariable(std::string const& typeName, Type::SPtr type) {
	return std::make_unique<JavaVariable>(typeName, type);
}

