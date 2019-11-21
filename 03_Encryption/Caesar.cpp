///////////////////////////////////////////////////////////////////////////
// Workfile :		Caesar.cpp
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	Encrypts and Decrypts a given text with Caesar encryption
// Revision :
///////////////////////////////////////////////////////////////////////////


//#include "Encryption.h"
#include <algorithm>
#include <iostream>
#include <string>

#include "Caesar.h"

size_t const range = 127;
std::string const WARNING_7BITCHAR = " is ignored, because no 7 Bit value";

//set file ending in base class
//base class constructor is only called from here
Caesar::Caesar() : Encryption::Encryption(".caesar"){
}

//encrypt a text with caesar encryption
void Caesar::DoCipher(std::string& text) {
	//encrpyt
	size_t i = 0;

	while (i < text.size()){
		//is it in the range of an 7 Bit char
		if (text[i] <= range){

			text[i] = (text[i] + mKey) % 128;
			++i;
		}
		else{
			//Warning that the out of range char is ignored
			std::cerr << "WARNING: " << text[i] << WARNING_7BITCHAR << std::endl;
			//remove that char
			text.erase(i, 1);
		}

	}
}

//encrypt a text with caesar encryption
void Caesar::DoDecipher(std::string& text) {
	//decrypt
	for (size_t i = 0; i < text.length(); i++) {
		//check if rotated over the end
		if (text[i] < mKey) {
			text[i] += 128;
		}
		text[i] = (text[i] - mKey);
	}
}