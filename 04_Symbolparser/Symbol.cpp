///////////////////////////////////////////////////////////////////////////
// Workfile :		Symbol.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Represents a part of a programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Symbol.h"

std::string Symbol::GetName() const{
	return mName;
}

Symbol::Symbol(std::string const& name) : mName(name) {};