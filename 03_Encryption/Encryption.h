///////////////////////////////////////////////////////////////////////////
// Workfile :		Encryption.h
// Author :			Marc Haunschmied, Markus Riegler
// Date :			November 2019
// Description :	Header for base class Encryption 
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption {
private:
	std::string mText;
	std::string const mEnding;

	//opening, reading, saving file
	void ReadFile(std::string const& fileName, std::string const& ending);
	//opening & writing text to file
	void WriteFile(std::string const& fileName);
protected:
	//Template Methods
	virtual void DoCipher(std::string& text) = 0;
	virtual void DoDecipher(std::string& text) = 0;
	//protected CTor 
	Encryption(std::string const& ending);
public:
	void Encrypt(std::string const& fileName);
	void Decrypt(std::string const& fileName);
};

#endif