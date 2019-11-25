///////////////////////////////////////////////////////////////////////////
// Workfile :		IECType.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in IEC Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////

#include "IECType.h"

std::string IECType::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				
		//check if TYPE is part of line
		if (line.find("TYPE") == 0) {	
			//find element after space
			mName = line.substr(line.find_last_of(" ") + 1);
		}
	}
	//return nothing
	return "";
}

//print type formatted to an output stream 
void IECType::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "TYPE " << mName << std::endl;
	}
}