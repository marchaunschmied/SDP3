///////////////////////////////////////////////////////////////////////////
// Workfile :		SymbolParser.cpp
// Author :			Markus Riegler
// Date :			22.11.2019
// Description :	Implementation of Class SymbolParser
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <string>
#include "SymbolParser.h"
///////////////////////////////////////////////////////////////////////////
//Error Constants
///////////////////////////////////////////////////////////////////////////
std::string const ERROR_READVAR = "ERROR in ReadVariables";
std::string const ERROR_READTYPES = "ERROR in ReadTypes";
std::string const ERROR_OPENING = "ERROR in opening of: ";
std::string const ERROR_NOFACT = "ERROR: No Factory set!";
std::string const ERROR_UN_TYPE = "ERROR: Unkwown Type: ";
std::string const ERROR_VARIABLE = "ERROR: Variablename already exists: ";



///////////////////////////////////////////////////////////////////////////
//Reads Variables from a Filestream and adds them to the Variable Container
///////////////////////////////////////////////////////////////////////////
void SymbolParser::ReadVariables(std::fstream& stream)
{
	//Read until the end of file is reached
	while (!stream.eof())
	{
		//stream bad?
		if (!stream.good())
		{
			std::cerr << ERROR_READVAR << std::endl;
			return;
		}
		//Buffer for reading
		std::string line = { 0 };
		//read one line
		std::getline(stream, line);
		//create empty Variable
		Variable::UPtr pVar = mFact->CreateVariable("",0);
		//Let the Variable extract data from line
		std::string type = pVar->ParseFromLine(line);
		//Add reference to type
		pVar->SetType(CheckType(type));
		//Add variable into the Container
		mVariables.emplace_back(pVar.release());
	}
}


///////////////////////////////////////////////////////////////////////////
//Reads Types from a Filestream and adds them to the Type Container
///////////////////////////////////////////////////////////////////////////
void SymbolParser::ReadTypes(std::fstream& stream)
{
	//Read until the end of file
	while (!stream.eof())
	{
		//stream bad?
		if(!stream.good())
		{
			std::cerr << ERROR_READTYPES << std::endl;
			return;
		}
		//buffer for reading
		std::string line = { 0 };
		//read one line
		std::getline(stream, line);
		//create empty type
		Type::SPtr pTyp = mFact->CreateType("");
		//let the type extract data from line
		pTyp->ParseFromLine(line);
		//add type to container
		mTypes.emplace_back(pTyp);
	}
}

///////////////////////////////////////////////////////////////////////////
//Opens a file with a given name
///////////////////////////////////////////////////////////////////////////
std::fstream SymbolParser::OpenFile(std::string const& path)
{
	std::fstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cerr << ERROR_OPENING << path << std::endl;
	}
	return file;
}

///////////////////////////////////////////////////////////////////////////
//Searches in mTypes for a spedific Type
//return a shared pointer to it if found, nullpointer if not
///////////////////////////////////////////////////////////////////////////
Type::SPtr SymbolParser::CheckType(std::string const& typeName)
{
	auto it = std::find_if(mTypes.cbegin(), mTypes.cend(),
					[typeName](auto t) {return t->GetName() == typeName; });
	//not found
	if (it == mTypes.cend())
	{
		return nullptr;
	}
	//found
	else
	{
		return *it;
	}
}

///////////////////////////////////////////////////////////////////////////
//Searches in mVariable if a Variable already exists
//returns true if found, false if not found
///////////////////////////////////////////////////////////////////////////
bool SymbolParser::CheckVariable(std::string const& variableName)
{
	auto it = std::find_if(mVariables.cbegin(), mVariables.cend(), 
			[variableName](auto& t) {return t->GetName() == variableName; });
	//returned iterator != end of container
	return it != mVariables.cend();
}

///////////////////////////////////////////////////////////////////////////
//Adds a type to the container if it doesnt already exist
///////////////////////////////////////////////////////////////////////////
void SymbolParser::AddType(std::string const& name)
{
	//factory set?
	if (mFact == nullptr)
	{
		throw std::string(ERROR_NOFACT);
		return;
	}
	//if not contained
	if (CheckType(name) == nullptr)
	{
		//add
		mTypes.emplace_back(mFact->CreateType(name));
	}
}

///////////////////////////////////////////////////////////////////////////
//Adds a Variable if the type exists and the Variable name doesnt
///////////////////////////////////////////////////////////////////////////
void SymbolParser::AddVariable(std::string const& name, std::string const& type)
{
	//factory set?
	if (mFact == nullptr)
	{
		throw std::string(ERROR_NOFACT);
		return;
	}
	//Look for type
	Type::SPtr pType = CheckType(type);
	//Type doesnt exist -> ERROR
	if (pType == nullptr)
	{
		std::cerr << ERROR_UN_TYPE << type << std::endl;
		return;
	}
	//Variable already exists -> ERROR
	if (CheckVariable(name))
	{
		std::cerr << ERROR_VARIABLE << name << std::endl;
		return;
	}
	else
	{
		//Everything OK -> add
		mVariables.emplace_back(mFact->CreateVariable(name, pType));
	}
}

///////////////////////////////////////////////////////////////////////////
//Changes the factory and saves/loads needed data
///////////////////////////////////////////////////////////////////////////
void SymbolParser::SetFactory(SymbolFactory::SPtr fact)
{
	std::fstream file;
	//when a fyctory is already set, save types and variables
	if (mFact != nullptr)
	{
		//Save Types
		file = OpenFile(mFact->GetTypeFilename());
		WriteFile(mTypes, file);
		file.close();

		//Save Variables
		file = OpenFile(mFact->GetVariableFilename());
		WriteFile(mVariables, file);
		file.close();
	}

	//clear containers for new data
	mTypes.clear();
	mVariables.clear();

	//set new Fatory
	mFact = fact;

	//Load Types
	file = OpenFile(mFact->GetTypeFilename());
	ReadTypes(file);
	file.close();

	//Load Variables
	file = OpenFile(mFact->GetVariableFilename());
	ReadVariables(file);
	file.close();
}
