#ifndef JAVA_VARIABLE_H
#define JAVA_VARIABLE_H

#include "Variable.h"

class JavaVariable : public Variable {
public:
	std::string ParseFromLine(std::string const& line) override;
};

#endif