///////////////////////////////////////////////////////////////////////////
// Workfile :		Mocca.h
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Header of class Mocca
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef MOCCA_H
#define MOCCA_H

#include "Object.h"
#include "ICoffee.h"

class Mocca : public ICoffee, public Object {
public:
	//functions from interface Coffee
	virtual double GetCost() const override;
	virtual std::string GetDescription() const override;
};

#endif
