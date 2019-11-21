///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "vld.h"
#include "Encryption.h"

#include "AdapterNortel.h"
#include "ClientNortel.h"

#include "AdapterEpcos.h"
#include "ClientEpcos.h"

using namespace std;

int main() {

	try
	{
		AdapterEpcos ep;
		ClientEpcos CEp;
		//Client Epcos test
		CEp.TestRSA(&ep);

		AdapterNortel no;
		ClientNortel CNo;
		//client Nortel test
		CNo.TestCaesar(&no);
		CNo.TestRSA(&no);
	}
	catch (exception const& ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}
	catch (std::string const& s)
	{
		cerr << s << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception" << endl;
		return 1;
	}

	return 0;
}