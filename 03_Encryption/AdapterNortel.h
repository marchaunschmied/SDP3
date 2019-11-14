///////////////////////////////////////////////////////////////////////////
// Workfile :		AdapterNortel.h
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef ADAPTER_NORTEL_H
#define ADAPTER_NORTEL_H

#include "INortel.h"
#include "Encryption.h"
#include "RSA.h"
#include "Caesar.h"

class AdapterNortel : public INortel {

private:
	RSA mRSA;
	Caesar mCaesar;
public:
	void Encipher(std::string const& fileName, TEncoding enc) override;
	void Decipher(std::string const& fileName, TEncoding enc) override;
};
#endif	
