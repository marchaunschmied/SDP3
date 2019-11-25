///////////////////////////////////////////////////////////////////////////
// Workfile :		SymbolFactory.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Returns a Programming language symbol
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "SymbolFactory.h"

std::string SymbolFactory::GetTypeFilename() const {
	return mTypeFileName;
}
std::string SymbolFactory::GetVariableFilename() const {
	return mVariableFileName;
}

SymbolFactory::SymbolFactory(std::string const& filenameT, std::string const& filenameV):
	mTypeFileName{filenameT}, mVariableFileName{filenameV}
{
}


