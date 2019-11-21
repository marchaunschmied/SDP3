#ifndef SYMBOL_PARSER_H
#define SYMBOL_PARSER_H


#include <fstream>
#include <list>
#include <memory>

#include "Object.h"
#include "SymbolFactory.h"
#include "Type.h"
#include "Variable.h"

class SymbolParser : public Object {
private:
	SymbolFactory::SPtr mFact = 0;
	std::list<Type::SPtr> mTypes;
	std::list<Variable::UPtr> mVariables;

	void ReadVariables(std::fstream& stream);
	void ReadTypes(std::fstream& stream);
	std::fstream OpenFile(std::string const& path);

	template <typename Cont>
	void WriteFile(Cont& symbols, std::fstream& ost) {
		for (auto& sym : symbols)
		{
			if (!stream.good())
			{
				std::cerr "ERROR: in write file" << std::endl;
				return;
			}
			ost << sym << std::endl;
		}
	}
	Type::SPtr CheckType(std::string const& typeName);
	bool CheckVariable(std::string const& variableName);

public:
	void AddType(std::string const& name);
	void AddVariable(std::string const& name, std::string const& type);
	void SetFactory(SymbolFactory::SPtr fact);

};

#endif