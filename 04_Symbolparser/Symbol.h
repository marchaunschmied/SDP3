#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

#include "Object.h"

class Symbol : public Object {
private:
	std::string mName;

public:
	virtual std::string ParseFromLine(std::string const& line) = 0;
	virtual void Print(std::ostream& ost) = 0;
	std::string GetName() const;
};

#endif