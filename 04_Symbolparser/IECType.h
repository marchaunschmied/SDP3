///////////////////////////////////////////////////////////////////////////
// Workfile :		IECType.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in IEC Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef IEC_TYPE_H
#define IEC_TYPE_H

#include "Type.h"

class IECType : public Type {
public:
	std::string ParseFromLine(std::string const& line) override;
	void Print(std::ostream& ost) override;
	IECType(std::string const& name) : Type(name) {};

};

#endif