#ifndef TYPE_H
#define TYPE_H

#include "Symbol.h"

class Type : public Symbol {
public:
	std::string ParseFromLine(std::string const& line) = 0;
};

#endif