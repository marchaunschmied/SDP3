///////////////////////////////////////////////////////////////////////////
// Workfile :		01_Fuhrpark.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "LogBook.h"

int main(){
    std::cout << "Hello World!\n";

	LogBook b1;

	b1.AddEntry("191021", 50);
	b1.AddEntry("191121", 77);
	b1.AddEntry("191211", 12);
	b1.AddEntry("200107", 491);
	b1.AddEntry("200113", 55);

	b1.PrintLog(std::cout);
	std::cout << b1.SumDistance();
}

