#include <string>

#include "RSA.h"




void RSA::DoCipher(std::string& text)
{
	for (size_t i = 0; i < text.size(); ++i)
	{
		size_t toEncrypt = text[i];
		size_t Faktor = text[i];
		for (size_t e = 0; e < mE; ++e)
		{
			toEncrypt *= Faktor;
			toEncrypt = toEncrypt % mN;
		}
		text[i] = toEncrypt;
	}
}

void RSA::DoDecipher(std::string& text)
{

}



RSA::RSA():Encryption(".txt.RSA")
{}
