#ifndef JAVA_SYMBOL_FACTORY_H
#define JAVA_SYMBOL_FACTORY_H

#include "SymbolFactory.h"
#include "JavaType.h"
#include "JavaVariable.h"

class JavaSymbolFactory : public SymbolFactory {
public:
	JavaType* CreateType();
	JavaVariable* CreateVariable();
};

#endif