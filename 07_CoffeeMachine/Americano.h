///////////////////////////////////////////////////////////////////////////
// Workfile :		Americano.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Americano
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef AMERICANO_H
#define AMERICANO_H

#include "Object.h"
#include "ICoffee.h"

class Americano : public ICoffee, public Object {
public:
	//functions from Interface Coffee
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
