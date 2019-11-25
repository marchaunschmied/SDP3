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
		//substring after first space
		mName = line.substr(line.find_first_of(" ") + 1);
		//substring to next space --> var name
		mName = mName.substr(0, mName.find_first_of(" ") + 1);
	
		//remove ';'
		mName.pop_back();
	}

	//string is after ': ' therefore 2 elemtents need to be skipped
	std::string type = line.substr(line.find_last_of(":") + 2);
	type.pop_back(); //remove ";"
	return type;
}

//print variable formatted to an output stream 
void IECVariable::Print(std::ostream& ost) {
	if (ost.good()) {
		ost << "VAR " << mName << " : " << mType->GetName() << ";" << std::endl;
	}
}