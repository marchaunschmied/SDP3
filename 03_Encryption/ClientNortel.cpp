///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientNortel.cpp
// Author :			Markus Riegler
// Date :			16. November 2019
// Description :	Client for Nortel--> Used for testing implementation
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "INortel.h"
#include "ClientNortel.h"

using namespace std;

void ClientNortel::TestRSA(INortel* inter) {

	cout << "Client Nortel RSA" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Encrypt" << endl;
	try {
		inter->Encipher("test4.txt", TEncoding::T_RSA);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Decrypt" << endl;
	try {
		inter->Decipher("test9.txt.RSA", TEncoding::T_RSA);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "No Filename in Decrypt" << endl;
	try {
		inter->Decipher("", TEncoding::T_RSA);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong File-Extension" << endl;
	try {
		inter->Encipher("ClientNortel.cpp", TEncoding::T_RSA);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Empty File" << endl;
	//empty
	inter->Encipher("testN.txt", TEncoding::T_RSA);
	inter->Decipher("testN.txt.RSA", TEncoding::T_RSA);
	cout << "--------------------------------------------------" << endl;
	cout << "All Printable 7 Bit ASCII" << endl;
	//7 Bit ASCII
	inter->Encipher("testN1.txt", TEncoding::T_RSA);
	inter->Decipher("testN1.txt.RSA", TEncoding::T_RSA);
	cout << "--------------------------------------------------" << endl;
	cout << "Text" << endl;
	//text with out of range chars
	inter->Encipher("testN2.txt", TEncoding::T_RSA);
	inter->Decipher("testN2.txt.RSA", TEncoding::T_RSA);
	cout << "--------------------------------------------------" << endl << endl;
}


void ClientNortel::TestCaesar(INortel* inter) {

	cout << "Client Nortel Caesar" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Encrypt" << endl;
	try {
		inter->Encipher("test4.txt", TEncoding::T_Caesar);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong Filename in Decrypt" << endl;
	try {
		inter->Decipher("test9.txt.caesar", TEncoding::T_Caesar);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "No Filename in Decrypt" << endl;
	try {
		inter->Decipher("", TEncoding::T_Caesar);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Wrong File-Extension" << endl;
	try {
		inter->Encipher("ClientNortel.cpp", TEncoding::T_Caesar);
	}
	catch (std::string const& s) {
		cerr << s << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Empty File" << endl;
	//empty
	inter->Encipher("test.txt", TEncoding::T_Caesar);
	inter->Decipher("test.txt.caesar", TEncoding::T_Caesar);
	cout << "--------------------------------------------------" << endl;
	cout << "All Printable 7 Bit ASCII" << endl;
	//7 Bit ASCII
	inter->Encipher("test1.txt", TEncoding::T_Caesar);
	inter->Decipher("test1.txt.caesar", TEncoding::T_Caesar);
	cout << "--------------------------------------------------" << endl;
	cout << "Text" << endl;
	//text with out of range chars
	inter->Encipher("test2.txt", TEncoding::T_Caesar);
	inter->Decipher("test2.txt.caesar", TEncoding::T_Caesar);
	cout << "--------------------------------------------------" << endl << endl;
}

