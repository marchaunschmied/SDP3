///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientEpcos.cpp
// Author :			Markus Riegler
// Date :			16. November 2019
// Description :	Client for Epcos --> Used for testing implementation
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ClientEpcos.h"

using namespace std;

void ClientEpcos::TestRSA(IEpcos* inter)
{
	cout << "Client Epcos" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Encrypt" << endl;
	try {
		inter->EncryptRSA("test5.txt");
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Decrypt" << endl;
	try {
		inter->DecryptRSA("test7.txt.RSA");
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "No Filename in Decrypt" << endl;
	try {
		inter->DecryptRSA("");
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong file-Extension" << endl;
	try {
		inter->DecryptRSA("ClientEpcos.cpp");
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Empty File" << endl;
	//empty
	inter->EncryptRSA("test.txt");
	inter->DecryptRSA("test.txt.RSA");
	cout << "--------------------------------------------------" << endl;
	cout << "All Printable 7 Bit ASCII" << endl;
	//7 Bit ASCII
	inter->EncryptRSA("test1.txt");
	inter->DecryptRSA("test1.txt.RSA");
	cout << "--------------------------------------------------" << endl;
	cout << "Text" << endl;
	//text with out of range chars
	inter->EncryptRSA("test2.txt");
	inter->DecryptRSA("test2.txt.RSA");
	cout << "--------------------------------------------------" << endl << endl;
}
