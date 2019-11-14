///////////////////////////////////////////////////////////////////////////
// Workfile :		AdapterNortel.cpp
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	Adapter calls right function for each TEnconding
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "AdapterNortel.h"

//encrypts a file in TEncoding encryption
void AdapterNortel::Encipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {
		mRSA.Encrypt(fileName);
	}
	else if (enc == T_Caesar) {
		mCaesar.Encrypt(fileName);
	}
	else {
		throw std::string{ "wrong encoding" };
	}
}

//decrypts a file in TEncoding encryption
void AdapterNortel::Decipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {
		mRSA.Decrypt(fileName);
	}
	else if (enc == T_Caesar) {
		mCaesar.Decrypt(fileName);
	}
	else {
		throw std::string{ "wrong encoding" };
	}
}