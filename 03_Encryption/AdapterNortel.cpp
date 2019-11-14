///////////////////////////////////////////////////////////////////////////
// Workfile :		AdapterNortel.cpp
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "AdapterNortel.h"

void AdapterNortel::Encipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {
		mRSA.Encrypt(fileName);
	}
	else if (enc == T_Caesar) {
		mCaesar.Encrypt(fileName);
	}
	else {

	}
}
void AdapterNortel::Decipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {
		mRSA.Decrypt(fileName);
	}
	else if (enc == T_Caesar) {
		mCaesar.Decrypt(fileName);
	}
	else {

	}
}