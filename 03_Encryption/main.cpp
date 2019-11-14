///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Encryption.h"
#include "RSA.h"
#include "Caesar.h"

int main() {

	//RSA rsa;
	//rsa.Encrypt("test.txt");

	Caesar c;
	c.Encrypt("test.txt");
	c.Decrypt("test.txt.caesar");



	return 0;
}