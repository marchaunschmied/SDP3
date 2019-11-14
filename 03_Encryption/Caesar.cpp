///////////////////////////////////////////////////////////////////////////
// Workfile :		Caesar.cpp
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


//#include "Encryption.h"
#include <algorithm>
#include <iostream>

#include "Caesar.h"

//set file ending in base class
//base class constructor is only called from here
Caesar::Caesar() : Encryption::Encryption(".caesar"){
}

//encrypt a text with caesar encryption
void Caesar::DoCipher(std::string& text) {
	//encrpyt
	for (size_t i = 0; i < text.length(); i++) {
		//std::cout << 0 + text[i] << " --> ";
		text[i] = (text[i] + mKey) % 128 ;
		//std::cout << 0 + text[i] << std::endl;
	}
	//std::cout << text << std::endl;
}

//encrypt a text with caesar encryption

void Caesar::DoDecipher(std::string& text) {
	//decrypt
	//std::cout << "==================================" << std::endl;
	for (size_t i = 0; i < text.length(); i++) {
		//std::cout << 0 + text[i] << " --> ";
		//check if rotated over the end
		if (text[i] < mKey) {
			text[i] += 128;
		}
		text[i] = (text[i] - mKey);
		//std::cout << 0 + text[i] << std::endl;
	}
	//std::cout << text << std::endl;
}