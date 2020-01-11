///////////////////////////////////////////////////////////////////////////
// Workfile :		Decaf.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Decaf
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef DECAF_H
#define DECAF_H

#include "Object.h"
#include "ICoffee.h"

class Decaf : public ICoffee, public Object {
public:
	//functions from interface Coffee
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif