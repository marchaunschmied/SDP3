#ifndef IEC_TYPE_H
#define IEC_TYPE_H

#include "Type.h"

class IECType : public Type {
public:
	std::string ParseFromLine(std::string const& line) override;
};

#endif