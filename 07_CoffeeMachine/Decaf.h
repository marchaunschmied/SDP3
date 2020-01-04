#ifndef DECAF_H
#define DECAF_H

#include "Object.h"
#include "Coffee.h"

class Decaf : public Coffee, public Object {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif