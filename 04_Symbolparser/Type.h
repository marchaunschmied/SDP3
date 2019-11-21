#ifndef TYPE_H
#define TYPE_H

#include "Symbol.h"

class Type : public Symbol {
public:
	std::string ParseFromLine(std::string const& line) override;
	void Print(std::ostream& ost) override;
	typedef std::shared_ptr<Type> SPtr;
};

#endif