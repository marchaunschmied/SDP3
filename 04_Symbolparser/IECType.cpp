///////////////////////////////////////////////////////////////////////////
// Workfile :		IECType.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in IEC Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "IECType.h"

std::string IECType::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				//benötigt obwohl von file?
		if (line.find("TYPE") == 0) {	// -''-
			mName = line.substr(line.find_last_of(" ") + 1);
		}
	}
	return "";
}
void IECType::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "TYPE " << mName << std::endl;
	}
}