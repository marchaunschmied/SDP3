#ifndef IEC_VARIABLE_H
#define IEC_VARIABLE_H

#include "Variable.h"

class IECVariable : public Variable {
public:
	std::string ParseFromLine(std::string const& line) override;
};

#endif