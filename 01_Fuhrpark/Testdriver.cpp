///////////////////////////////////////////////////////////////////////////
// Workfile :		Testdriver.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "LogBook.h"
#include "Car.h"
#include "Truck.h"
#include "MotorCycle.h"
#include <string>

using namespace std;

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
	std::cout << b1.SumDistance() << endl;

	Car c1{ "Seat","Ibiza" ,"FR-123AB" , TFuel::DIESEL };
	c1.Print(cout);

	Truck t1{ "Mercedes", "Actros", "L-456DS", TFuel::DIESEL };
	t1.Print(cout);

	Motorcycle m1{ "Vespa", "GTS 300", "PE-2WER", TFuel::PETROL };
	m1.Print(cout);

	cout << boolalpha << c1.AddLogEntry("191005", 123) << endl;
	cout << boolalpha << c1.AddLogEntry("191010", 1) << endl;
	cout << boolalpha << c1.AddLogEntry("191021", 24) << endl;

	cout << boolalpha << t1.AddLogEntry("191021", 1000) << endl;

	cout << boolalpha << m1.AddLogEntry("191021", 73) << endl;


	c1.Print(cout);
	t1.Print(cout);
	m1.Print(cout);
	

	return 0;
}

