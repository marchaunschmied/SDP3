///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaSymbolFactory.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "JavaSymbolFactory.h"
#include <memory>

Type::SPtr JavaSymbolFactory::CreateType(std::string const& typeName)  {
	return std::make_shared<JavaType>(typeName);
}
Variable::UPtr JavaSymbolFactory::CreateVariable(std::string const& typeName)  {
	return std::make_unique<JavaVariable>(typeName);
}
