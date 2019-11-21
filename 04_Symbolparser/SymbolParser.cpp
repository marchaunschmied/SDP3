#include <algorithm>
#include <string>
#include "SymbolParser.h"

void SymbolParser::ReadVariables(std::fstream& stream)
{
	while (!stream.eof())
	{
		std::string line = { 0 };
		std::getline(stream, line);
		Variable::UPtr pVar = mFact->CreateVariable("",0);
		std::string type = pVar->ParseFromLine(line);
		pVar->SetType(CheckType(type));
		mVariables.emplace_back(pVar.release());
	}
}

void SymbolParser::ReadTypes(std::fstream& stream)
{
	while (!stream.eof())
	{
		std::string line = { 0 };
		std::getline(stream, line);
		Type::SPtr pTyp = mFact->CreateType("");
		pTyp->ParseFromLine(line);
		mTypes.emplace_back(pTyp);
	}
}

std::fstream SymbolParser::OpenFile(std::string const& path)
{
	std::fstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cerr << "ERROR in opening of: " << path << std::endl;
	}
	return file;
}

Type::SPtr SymbolParser::CheckType(std::string const& typeName)
{
	auto it = std::find_if(mTypes.cbegin(), mTypes.cend(), [typeName](auto t) {return t->GetName() == typeName; });
	if (it == mTypes.cend())
	{
		return nullptr;
	}
	else
	{
		return *it;
	}
}

bool SymbolParser::CheckVariable(std::string const& variableName)
{
	auto it = std::find_if(mVariables.cbegin(), mVariables.cend(), [variableName](auto& t) {return t->GetName() == variableName; });
	return it != mVariables.cend();
}

void SymbolParser::AddType(std::string const& name)
{
	if (mFact == nullptr)
	{
		throw std::string("ERROR: No Factory set!");
		return;
	}
	if (CheckType(name) != nullptr)
	{
		mTypes.emplace_back(mFact->CreateType(name));
	}
}

void SymbolParser::AddVariable(std::string const& name, std::string const& type)
{
	if (mFact == nullptr)
	{
		throw std::string("ERROR: No Factory set!");
		return;
	}
	Type::SPtr pType = CheckType(type);
	if (pType == nullptr)
	{
		std::cerr << "ERROR: Unkwown Type: " << type << std::endl;
		return;
	}
	if (CheckVariable(name))
	{
		std::cerr << "ERROR: Variablename already exists: " << name << std::endl;
		return;
	}
	else
	{
		mVariables.emplace_back(mFact->CreateVariable(name, pType));
	}
}

void SymbolParser::SetFactory(SymbolFactory::SPtr fact)
{
	std::fstream file;
	if (mFact != nullptr)
	{
		file = OpenFile(mFact->GetTypeFilename());
		WriteFile(mTypes, file);
		file.close();

		file = OpenFile(mFact->GetVariableFilename());
		WriteFile(mVariables, file);
		file.close();
	}

	mTypes.clear();
	mVariables.clear();

	mFact = fact;
	file = OpenFile(mFact->GetTypeFilename());
	ReadTypes(file);
	file.close();

	file = OpenFile(mFact->GetVariableFilename());
	ReadVariables(file);
	file.close();
	
}
