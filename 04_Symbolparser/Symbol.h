///////////////////////////////////////////////////////////////////////////
// Workfile :		Symbol.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

#include "Object.h"

class Symbol : public Object {
protected:
	std::string mName;
public:
	virtual std::string ParseFromLine(std::string const& line) = 0;
	virtual void Print(std::ostream& ost) = 0;

	std::string GetName();

	Symbol(std::string const& name) : mName(name) {};

};

#endif