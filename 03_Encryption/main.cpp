///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Encryption.h"
#include "RSA.h"

#include "AdapterNortel.h"
#include "ClientNortel.h"

int main() {
	AdapterNortel nortel;

	ClientNortel nortelTest;
	nortelTest.TestCaesar(&nortel);



	RSA rsa;
	rsa.Encrypt("test.txt");
	rsa.Decrypt("test1.txt.RSA");


	return 0;
}