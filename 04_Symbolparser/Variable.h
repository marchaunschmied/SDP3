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
	virtual void SetType(Type::SPtr const& type);


	typedef std::unique_ptr<Variable> UPtr;
};

#endif