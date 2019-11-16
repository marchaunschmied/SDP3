///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientEpcos.h
// Author :			Markus Riegler
// Date :			14.11.2019
// Description :	Header of Client-class Epcos 
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#ifndef CLIENT_EPCOS_H
#define CLIENT_EPCOS_H

#include "IEpcos.h"

class ClientEpcos {
public:
	void TestRSA(IEpcos* inter);
};
#endif