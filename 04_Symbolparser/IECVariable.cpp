///////////////////////////////////////////////////////////////////////////
// Workfile :		IECVariable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "IECVariable.h"

std::string IECVariable::ParseFromLine(std::string const& line) {
	if (!line.empty()) {				//benötigt obwohl von file?
		//if (line.find(mType) == 0) {	// -''-
			mName = line.substr(line.find_last_of(" ") + 1);
		//}
	}
	return "";
}
void IECVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "VAR " << mName << " : " << mType->GetName() << ";" << std::endl;
	}
}