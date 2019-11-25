///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaType.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in Java Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "JavaType.h"

std::string JavaType::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				
		if (line.find("class") == 0) {	
			mName = line.substr(line.find_last_of(" ") + 1);
		}
	}
	return "";
}
void JavaType::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "class " << mName << std::endl;
	}
}