#ifndef MOCCA_H
#define MOCCA_H

#include "Object.h"
#include "Coffee.h"

class Mocca : public Coffee, public Object {
public:
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
