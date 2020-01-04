#ifndef AMERICANO_H
#define AMERICANO_H

#include "Object.h"
#include "Coffee.h"

class Americano : public Coffee, public Object {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
