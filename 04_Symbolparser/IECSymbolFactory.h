#ifndef IEC_SYMBOL_FACTORY_H
#define IEC_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "IECType.h"
#include "IECVariable.h"

class IECSymbolFactory : public SymbolFactory {
public:
	IECType* CreateType();
	IECVariable* CreateVariable();
};

#endif