///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaVariable.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Variable in Java Programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef JAVA_VARIABLE_H
#define JAVA_VARIABLE_H

#include "Variable.h"

class JavaVariable : public Variable {
public:
	std::string ParseFromLine(std::string const& line) override;
	void Print(std::ostream& ost) override;

	JavaVariable(std::string const& name, Type::SPtr type) : Variable(name) { SetType(type); };
};

#endif