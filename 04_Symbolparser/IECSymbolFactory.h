///////////////////////////////////////////////////////////////////////////
// Workfile :		IECSymbolFactory.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef IEC_SYMBOL_FACTORY_H
#define IEC_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "IECType.h"
#include "IECVariable.h"
#include "SingletonBase.h"

class IECSymbolFactory : public SymbolFactory, public SingletonBase<IECSymbolFactory> {
public:
	Type::SPtr CreateType(std::string const& typeName) override;
	Variable::UPtr CreateVariable(std::string const& typeName, Type::SPtr type) override;

private:
	friend class SingletonBase<IECSymbolFactory>;
	IECSymbolFactory() : SymbolFactory("IECTypes.sym", "IECVars.sym") {};
};

#endif