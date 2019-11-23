#ifndef SYMBOL_PARSER_H
#define SYMBOL_PARSER_H

#include <fstream>
#include <list>

#include "Object.h"
#include "SymbolFactory.h"
#include "Type.h"
#include "Variable.h"

class SymbolParser : public Object {
private:
	//SymbolFactory<T>::SPtr mFact;
	std::list<Type::SPtr> mTypes;
	std::list<Variable::UPtr> mVariables;

	void ReadVariables(std::string const& path);
	void ReadTypes(std::string const& path);
	std::fstream& OpenFile(std::string path);

	template <typename TItor>
	void WriteFile(TItor begin, TItor end, std::fstream& ost) {
		
	}
public:
	void AddType(std::string const& name);
	void AddVariable(std::string const& name, std::string const& type);
	//void SetFactory(std::unique_ptr<SymbolFactory> fact);
	Type::SPtr CheckType(std::string const& typeName);

};

#endif