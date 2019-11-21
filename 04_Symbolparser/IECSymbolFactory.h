#ifndef IEC_SYMBOL_FACTORY_H
#define IEC_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "IECType.h"
#include "IECVariable.h"

class IECSymbolFactory : public SymbolFactory {
public:
	Type::SPtr CreateType(std::string const& typeName) override;
	Variable::UPtr CreateVariable(std::string const& typeName) override;
};

#endif