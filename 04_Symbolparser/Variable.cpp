///////////////////////////////////////////////////////////////////////////
// Workfile :		Variable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Represents an Variable in a programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Variable.h"

void Variable::SetType(Type::SPtr const& type) {
	mType = type;
}