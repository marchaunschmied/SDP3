///////////////////////////////////////////////////////////////////////////
// Workfile :		IECVariable.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Variable in IEC Progamming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "IECVariable.h"

std::string IECVariable::ParseFromLine(std::string const& line) {
	if (!line.empty()) {		
		mName = line.substr(line.find_last_of(" ") + 1);
		mName.pop_back();
	}
	std::string type  = line.substr(line.find_last_of(":") + 2);
	type.pop_back(); //remove ";"
	return type;
}
void IECVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "VAR " << mName << " : " << mType->GetName() << ";" << std::endl;
	}
}