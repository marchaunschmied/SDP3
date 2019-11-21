#ifndef VARIABLE_H
#define VARIABLE_H

#include "Symbol.h"
#include "Type.h"

class Variable : public Symbol {
private:
	Type* mType;
public:
	std::string ParseFromLine(std::string const& line) = 0;
	void SetType(Type* type);
};

#endif