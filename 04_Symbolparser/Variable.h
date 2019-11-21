#ifndef VARIABLE_H
#define VARIABLE_H

#include "Symbol.h"
#include "Type.h"

class Variable : public Symbol {
private:
	Type::SPtr mType;
public:
	std::string ParseFromLine(std::string const& line) override;
	void SetType(Type::SPtr const& type);
	void Print(std::ostream& ost) = 0;

	typedef std::unique_ptr<Variable> UPtr;
};

#endif