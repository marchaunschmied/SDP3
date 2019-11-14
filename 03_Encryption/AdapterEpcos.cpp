///////////////////////////////////////////////////////////////////////////
// Workfile :		AdapterEpcos.h
// Author :			Markus Riegler
// Date :			14.11.2019
// Description :	Implemantation of adapterclass for IEpcos
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "AdapterEpcos.h"

//forward the Filename to Encrypt from RSA
void AdapterEpcos::EncryptRSA(std::string const& fileName)
{
	mRSA.Encrypt(fileName);
}
//forward the Filename to Decrypt from RSA
void AdapterEpcos::DecryptRSA(std::string const& fileName)
{
	mRSA.Decrypt(fileName);
}
