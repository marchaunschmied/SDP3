///////////////////////////////////////////////////////////////////////////
// Workfile :		JavaType.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Type in Java programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef JAVA_TYPE_H
#define JAVA_TYPE_H

#include "Type.h"

class JavaType : public Type {
public:
	std::string ParseFromLine(std::string const& line) override;
	void Print(std::ostream& ost) override;
	JavaType(std::string const& name) : Type(name) {};
};

#endif