///////////////////////////////////////////////////////////////////////////
// Workfile :		RSA.cpp
// Author :			Markus Riegler
// Date :			14.11.2019
// Description :	Implementation of class RSA
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
#include "RSA.h"

///////////////////////////////////////////////////////////////////////////
size_t const range = 127;
std::string const WARNING_7BITCHAR = " is ignored, because no 7 Bit value";

///////////////////////////////////////////////////////////////////////////
//CTor sets the extension for the encrypted Filename
///////////////////////////////////////////////////////////////////////////
RSA::RSA() :Encryption(".RSA")
{}

///////////////////////////////////////////////////////////////////////////
//Helpfunction which calculates the RSA value with the given key
///////////////////////////////////////////////////////////////////////////
unsigned char RSA::CalcRSA(unsigned char c, size_t key)
{
	size_t tmpRes = c;
	size_t Faktor = c;
	//multiply for key - 1 times
	for (size_t i = 1; i < key; ++i)
	{
		tmpRes *= Faktor;
		tmpRes = tmpRes % mN;
	}
	return tmpRes;
}

///////////////////////////////////////////////////////////////////////////
//Encrypt the given String
///////////////////////////////////////////////////////////////////////////
void RSA::DoCipher(std::string& text)
{
	size_t i = 0;
	//run through the string
	while(i < text.size())
	{
		//is it in the range of an 7 Bit char
		if (text[i] <= range)
		{
			//Calculate with private key
			text[i] = CalcRSA(text[i], mE);
			++i;
		}
		else
		{
			//Warning that the out of range char is ignored
			std::cerr << "WARNING: " << text[i] << WARNING_7BITCHAR << std::endl;
			//remove that char
			text.erase(i,1);
		}
		
	}
}

///////////////////////////////////////////////////////////////////////////
//Decrypt given string
///////////////////////////////////////////////////////////////////////////
void RSA::DoDecipher(std::string& text)
{
	//Calculate the new value of every char with public key
	for (size_t i = 0; i < text.size(); ++i)
	{
		text[i] = CalcRSA(text[i], mD);
	}
}



