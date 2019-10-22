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
	b1.AddEntry("191121", 77);
	b1.AddEntry("191211", 12);
	b1.AddEntry("200107", 491);
	b1.AddEntry("200113", 55);

	//Test Print 
	b1.PrintLog(std::cout);

	//Test SumDistance
	std::cout << b1.SumDistance();
}

