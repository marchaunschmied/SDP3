///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientNortel.h
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef CLIENT_NORTEL_H
#define CLIENT_NORTEL_H

#include "INortel.h"

class ClientNortel {
public:
	void TestRSA(INortel* inter);
	void TestCaesar(INortel* inter);

};
#endif