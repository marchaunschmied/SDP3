///////////////////////////////////////////////////////////////////////////
// Workfile :		RSA.h
// Author :			Markus Riegler
// Date :			14.11.2019
// Description :	Header of class RSA
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#ifndef RSA_H
#define RSA_H

#include "Encryption.h"

class RSA : public Encryption{
private:
	size_t const mN = 187;
	size_t const mE = 7;	//private Key
	size_t const mD = 23;	//public Key

	//private help functions
	unsigned char CalcRSA(unsigned char c, size_t key);
	
protected:
	//functions for Template Method
	virtual void DoCipher(std::string& text) override;
	virtual void DoDecipher(std::string& text) override;

public:
	RSA();

};

#endif