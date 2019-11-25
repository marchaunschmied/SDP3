///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaType.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in Java Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////

#include "JavaType.h"

std::string JavaType::ParseFromLine(std::string const& line) {
	//check if line is empty
	if (!line.empty()) {	
		//check if "class" is part of the line
		if (line.find("class") == 0) {	
			//find element after space
			mName = line.substr(line.find_last_of(" ") + 1);
		}
	}
	//return nothing
	return "";
}
//print type formatted to an output stream 
void JavaType::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "class " << mName << std::endl;
	}
}