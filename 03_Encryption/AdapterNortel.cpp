#include "AdapterNortel.h"

void AdapterNortel::Encipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {

	}
	else if (enc == T_Caesar) {
		mCaesar.Encrypt(fileName);
	}
	else {

	}
}
void AdapterNortel::Decipher(std::string const& fileName, TEncoding enc) {
	if (enc == T_RSA) {

	}
	else if (enc == T_Caesar) {
		mCaesar.Decrypt(fileName);
	}
	else {

	}
}