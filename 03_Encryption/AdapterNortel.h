#ifndef ADAPTER_NORTEL_H
#define ADAPTER_NORTEL_H

#include "INortel.h"
#include "Encryption.h"
#include "RSA.h"
#include "Caesar.h"

class AdapterNortel : public INortel {
public:
	//RSA mRSA;
	Caesar mCaesar;

	void Encipher(std::string const& fileName, TEncoding enc) override;
	void Decipher(std::string const& fileName, TEncoding enc) override;
};
#endif	
