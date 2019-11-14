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

	//RSA rsa;
	//rsa.Encrypt("test.txt");

	AdapterNortel nortel;

	ClientNortel nortelTest;
	nortelTest.TestCaesar(&nortel);



	return 0;
}