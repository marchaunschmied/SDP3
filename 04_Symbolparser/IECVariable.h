///////////////////////////////////////////////////////////////////////////
// Workfile :		IECVariable.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef IEC_VARIABLE_H
#define IEC_VARIABLE_H

#include "Variable.h"

class IECVariable : public Variable {
public:
	std::string ParseFromLine(std::string const& line) override;
	void Print(std::ostream& ost) override;

	IECVariable(std::string const& name, Type::SPtr type) : Variable(name) { SetType(type); };

};

#endif