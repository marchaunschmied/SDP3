///////////////////////////////////////////////////////////////////////////
// Workfile :		Encryption.h
// Author :			Marc Haunschmied, Markus Riegler
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption {
private:
	std::string mText;
	std::string const mEnding;

	void ReadFile(std::string const& fileName, std::string const& ending);
	void WriteFile(std::string const& fileName);
protected:
	virtual void DoCipher(std::string& text) = 0;
	virtual void DoDecipher(std::string& text) = 0;
	Encryption(std::string const& ending);
public:
	void Encrypt(std::string const& fileName);
	void Decrypt(std::string const& fileName);
};

#endif