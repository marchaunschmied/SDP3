///////////////////////////////////////////////////////////////////////////
// Workfile :		Type.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef TYPE_H
#define TYPE_H

#include "Symbol.h"

class Type : public Symbol {
public:
	virtual std::string ParseFromLine(std::string const& line) = 0;
	virtual void Print(std::ostream& ost) = 0;
	typedef std::shared_ptr<Type> SPtr;

	Type(std::string const& name): Symbol(name){};
};

#endif