///////////////////////////////////////////////////////////////////////////
// Workfile :		Testdriver.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "LogBook.h"

int main() {

	//Test adding Entries to the LogBook
	LogBook b1;

	b1.AddEntry("191021", 50);
	b1.AddEntry("190121", 77);
	b1.AddEntry("191211", 12);
	b1.AddEntry("200107", 491);
	b1.AddEntry("200113", 55);
	b1.AddEntry("191231", 10);
	b1.AddEntry("101010", 120);
 	b1.AddEntry("190501", 5);
	b1.AddEntry("211010", 2);
	b1.AddEntry("111111", 90);
	b1.AddEntry("110202", 22);
	b1.AddEntry("111231", 53);
	b1.AddEntry("211008", 123);
	b1.AddEntry("210910", 1);
	b1.AddEntry("080808", 24);
	b1.AddEntry("070707", 2);
	b1.AddEntry("111111", 49);
	b1.AddEntry("080412", 235);
	b1.AddEntry("asdfgh", 234);
	//Test Print 
	b1.PrintLog(std::cout);

	//Test SumDistance
	std::cout << b1.SumDistance();
}

