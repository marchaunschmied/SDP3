///////////////////////////////////////////////////////////////////////////
// Workfile :		Testdriver.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "vld.h"
#include "Fleet.h"

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
	cout << endl << endl;

	Fleet f1;
	cout << f1 << endl;
	cout << f1.GetTotalDistance() << endl;

	cout << boolalpha << f1.AddVehicle(make_shared<Car>(c1)) << endl;
	cout << boolalpha << f1.AddVehicle(make_shared<Car>(c1)) << endl;
	cout << boolalpha << f1.AddVehicle(make_shared<Truck>(t1)) << endl;
	cout << boolalpha << f1.AddVehicle(make_shared<Motorcycle>(m1)) << endl << endl;

	cout << f1 << endl;
	cout << f1.GetTotalDistance() << endl;

	

	

	return 0;
}

