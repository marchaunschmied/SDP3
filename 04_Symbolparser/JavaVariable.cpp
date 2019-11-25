///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaVariable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Variable in Java Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "JavaVariable.h"



JavaVariable::JavaVariable(std::string const& name, Type::SPtr type) : Variable(name) { SetType(type); };

std::string JavaVariable::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				
		//get first element before a space
		mName = line.substr(line.find_last_of(" ") + 1);

		//remove ';*
		mName.erase(std::remove_if(mName.begin(), mName.end(), [](char const& c) {
			return c == ';';
			}),mName.end());
	}

	//parse type
	return line.substr(0, line.find(' '));
}

//print variable formatted to an output stream 
void JavaVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << mType->GetName() << " " << mName << ";" << std::endl;
	}
}
