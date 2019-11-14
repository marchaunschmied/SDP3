///////////////////////////////////////////////////////////////////////////
// Workfile :		Encryption.cpp
// Author :			Marc Haunschmied, Markus Riegler
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <iostream>
#include <sstream>
#include "Encryption.h"


Encryption::Encryption(std::string const& ending) : mEnding(ending) {
}


std::string Encryption::ReadFile(std::string const& fileName) {
	if (fileName.length() > 0) {
		std::ifstream file;
		std::stringstream buffer;

	  file.open(fileName, std::ios::binary);


		if (file.good()) {
			if (buffer.good()) {
				buffer << file.rdbuf();
				mText = buffer.str();
			}
			else {
				throw std::string{ "error reading file" };
			}
		}
		file.close();
	}
	return "";
}

void Encryption::WriteFile(std::string const& fileName){
	if (fileName.length() > 0) {
		std::ofstream file;
		file.open(fileName, std::ostream::binary | std::ofstream::trunc);
		if (file.good()) {
			file << mText;
		}
		else {
			throw std::string{ "error writing file" };
		}
		file.close();
	}
}


void Encryption::Encrypt(std::string const& fileName) {
	Encryption::ReadFile(fileName);
	DoCipher(mText);
	Encryption::WriteFile(fileName + mEnding);
	mText.clear();
}

void Encryption::Decrypt(std::string const& fileName) {
	Encryption::ReadFile(fileName);
	DoDecipher(mText);
	Encryption::WriteFile(fileName + ".decrypted");
	mText.clear();
}