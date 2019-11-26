///////////////////////////////////////////////////////////////////////////
// Workfile :		Variable.h
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	Represents a Variable in a programming language
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef VARIABLE_H
#define VARIABLE_H

#include "Symbol.h"
#include "Type.h"

class Variable : public Symbol {
protected:
	Type::SPtr mType;
public:
	virtual std::string ParseFromLine(std::string const& line) = 0;
	virtual void Print(std::ostream& ost) = 0;
	void SetType(Type::SPtr const& type);

	Variable(std::string const& name);

	typedef std::unique_ptr<Variable> UPtr;
};

#endif