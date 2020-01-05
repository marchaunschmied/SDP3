///////////////////////////////////////////////////////////////////////////
// Workfile :		Espresso.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Espresso
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "Object.h"
#include "ICoffee.h"

class Espresso : public ICoffee, public Object {
public:
	//functions from interface Coffee
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
