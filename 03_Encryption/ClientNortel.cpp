///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientNortel.cpp
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include "INortel.h"
#include "ClientNortel.h"

void ClientNortel::TestRSA(INortel* inter) {
	inter->Encipher("test.txt", TEncoding::T_RSA);
	inter->Decipher("test.txt.RSA", TEncoding::T_RSA);
}
void ClientNortel::TestCaesar(INortel* inter) {
	inter->Encipher("test.txt", TEncoding::T_Caesar);
	inter->Decipher("test.txt.caesar", TEncoding::T_Caesar);
}

