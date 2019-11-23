///////////////////////////////////////////////////////////////////////////
// Workfile :		IECSymbolFactory.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "IECSymbolFactory.h"

Type::SPtr IECSymbolFactory::CreateType(std::string const& typeName) {
	return std::make_shared<IECType>(typeName);
}
Variable::UPtr IECSymbolFactory::CreateVariable(std::string const& typeName) {
	return std::make_unique<IECVariable>(typeName);
}

