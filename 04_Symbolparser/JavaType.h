#ifndef JAVA_TYPE_H
#define JAVA_TYPE_H

#include "Type.h"

class JavaType : public Type {
public:
	std::string ParseFromLine(std::string const& line) override;
};

#endif