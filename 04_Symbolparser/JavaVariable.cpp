///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaVariable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Variable in Java Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "JavaVariable.h"

std::string JavaVariable::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				//benötigt obwohl von file?
		mName = line.substr(line.find_last_of(" "));
	}
	return line.substr(0, line.find(' '));
}
void JavaVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << mType->GetName() << " " << mName << ";" << std::endl;
	}
}
