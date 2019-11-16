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
#include <filesystem>
#include "Encryption.h"

//CTor sets the File-Extension
Encryption::Encryption(std::string const& ending) : mEnding(ending) {}


///////////////////////////////////////////////////////////////////////////
//Function to open the file, reading it and saving the data into a string
///////////////////////////////////////////////////////////////////////////
void Encryption::ReadFile(std::string const& fileName, std::string const& ending) {
	//Filename given?
	if (fileName.length() > 0) {

		//Check if correct File-Extension
		std::filesystem::path f{ fileName };
		if (f.extension() != ending)
		{
			throw std::string{ "File: " + fileName + " wrong ending -> " + ending + " needed." };
		}

		//create streams
		std::ifstream file;
		std::stringstream buffer;

		file.open(fileName, std::ios::binary);

		//file openin OK?
		if (file.good()) {
			//read into a buffer
			if (buffer.good()) {
				buffer << file.rdbuf();
				//save read text
				mText = buffer.str();
			}
		}
		else {
			throw std::string{ "error reading file: " + fileName };
		}
		file.close();
	}
}

///////////////////////////////////////////////////////////////////////////
//Function to open the file and writing mText into it
///////////////////////////////////////////////////////////////////////////
void Encryption::WriteFile(std::string const& fileName){
	//Filename given
	if (fileName.length() > 0) {
		//open file
		std::ofstream file;
		file.open(fileName, std::ostream::binary | std::ofstream::trunc);
		//Correct opened
		if (file.good()) {
			file << mText;
		}
		else {
			throw std::string{ "error writing file: " + fileName };
		}
		file.close();
	}
}


///////////////////////////////////////////////////////////////////////////
//Function to Encrypt the File with the given name
///////////////////////////////////////////////////////////////////////////
void Encryption::Encrypt(std::string const& fileName) {
	ReadFile(fileName, ".txt");
	DoCipher(mText);
	WriteFile(fileName + mEnding);
	mText.clear();
}

///////////////////////////////////////////////////////////////////////////
//Function to decrypt the File with the given name
///////////////////////////////////////////////////////////////////////////
void Encryption::Decrypt(std::string const& fileName) {
	ReadFile(fileName, mEnding);
	DoDecipher(mText);
	WriteFile(fileName + ".decrypted");
	mText.clear();
}