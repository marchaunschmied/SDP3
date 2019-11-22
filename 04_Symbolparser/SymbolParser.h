///////////////////////////////////////////////////////////////////////////
// Workfile :		SymbolParser.h
// Author :			Markus Riegler
// Date :			22.11.2019
// Description :	Header of Class SymbolParser
// Revision :		1
///////////////////////////////////////////////////////////////////////////
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
	//private member
	SymbolFactory::SPtr mFact = 0;
	std::list<Type::SPtr> mTypes;
	std::list<Variable::UPtr> mVariables;

	//Help functions
	//Reads Varibles from a file
	void ReadVariables(std::fstream& stream);
	//Reads types from a file
	void ReadTypes(std::fstream& stream);
	//opens a file with a given name
	std::fstream OpenFile(std::string const& path);

	//writes a container into a Filestream
	template <typename Cont>
	void WriteFile(Cont& symbols, std::fstream& ost) {
		for (auto& sym : symbols)
		{
			if (!stream.good())
			{
				std::cerr "ERROR: in write file" << std::endl;
				return;
			}
			ost << *sym << std::endl;
		}
	}
	//Checks if the type is known
	Type::SPtr CheckType(std::string const& typeName);
	//Checks if a Variable already exists
	bool CheckVariable(std::string const& variableName);

public:
	void AddType(std::string const& name);
	void AddVariable(std::string const& name, std::string const& type);
	void SetFactory(SymbolFactory::SPtr fact);

};

#endif