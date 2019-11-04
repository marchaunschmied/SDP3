///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientTest.h
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H

#include "ICompany.h"

class ClientTest : public Object {
public:
	void Test(ICompany* comp);
};

#endif