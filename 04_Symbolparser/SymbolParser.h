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

	std::list<Type::SPtr> mTypes;
	std::list<Variable::UPtr> mVariables;
	SymbolFactory* mFact = nullptr;

	//Help functions
	//Reads Varibles from a file
	void ReadVariables(std::ifstream& stream);
	//Reads types from a file
	void ReadTypes(std::ifstream& stream);
	//opens a file with a given name
	std::ifstream OpenFileRead(std::string const& path);
	std::ofstream OpenFileWrite(std::string const& path);

	//Reads Symbol files
	void LoadSymbols();
	//Saves Symbol files
	void SaveSymbols();

	std::string const ERROR_WRITE = "ERROR: in write file";

	///////////////////////////////////////////////////////////////////////////
	//writes a container into a Filestream
	///////////////////////////////////////////////////////////////////////////
	template <typename Cont, typename stream>
	void WriteFile(Cont const& symbols, stream& ost) {
		for (auto& sym : symbols)
		{
			if (!ost.good())
			{
				std::cerr << ERROR_WRITE << std::endl;
				return;
			}
			sym->Print(ost);
		}
	}

	//Checks if the type is known
	Type::SPtr CheckType(std::string const& typeName);
	//Checks if a Variable already exists
	bool CheckVariable(std::string const& variableName);

	//Copy and = deleted
	SymbolParser(SymbolParser const& s) = delete;
	SymbolParser& operator =(SymbolParser const& s) = delete;

public:
	void AddType(std::string const& name);
	void AddVariable(std::string const& name, std::string const& type);
	void SetFactory(SymbolFactory* fact);

	SymbolParser() = default;
	~SymbolParser();
};

#endif