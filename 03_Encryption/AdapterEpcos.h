///////////////////////////////////////////////////////////////////////////
// Workfile :		AdapterEpcos.h
// Author :			Markus Riegler
// Date :			14.11.2019
// Description :	Header of adapterclass for IEpcos
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef ADAPTER_EPCOS_H
#define ADAPTER_EPCOS_H

#include "IEpcos.h"
#include "Encryption.h"
#include "RSA.h"


class AdapterEpcos : public IEpcos {

public:
	//override the functions of the Interface
	virtual void EncryptRSA(std::string const& fileName) override;
	virtual void DecryptRSA(std::string const& fileName) override;

private:
	RSA mRSA;
};
#endif	
