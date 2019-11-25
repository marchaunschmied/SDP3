///////////////////////////////////////////////////////////////////////////
// Workfile :		Variable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Represents an Variable in a programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Variable.h"

Variable::Variable(std::string const& name) : Symbol(name) {};

void Variable::SetType(Type::SPtr const& type) {
	mType = type;
}