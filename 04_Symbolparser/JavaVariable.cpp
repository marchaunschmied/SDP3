///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaVariable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "JavaVariable.h"

std::string JavaVariable::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				//benötigt obwohl von file?
		//if (line.find("class") == 0) {	// -''-
			mName = line.substr(line.find_last_of(" ") + 1);
		//}
	}
	return "";
}
void JavaVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << mType->GetName() << " " << mName << std::endl;
	}
}
