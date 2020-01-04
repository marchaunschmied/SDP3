#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "Object.h"
#include "Coffee.h"

class Espresso : public Coffee, public Object {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
