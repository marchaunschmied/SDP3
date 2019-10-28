///////////////////////////////////////////////////////////////////////////
// Workfile :		Testdriver.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	This is the testdriver for Fleet and LogBook. Adding
//					vehicels, removing and searching is performed. 
//					Fleet Assignment is tested 
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Fleet.h"

#include "LogBook.h"
#include "Car.h"
#include "Truck.h"
#include "MotorCycle.h"
#include <string>

using namespace std;

int main() {

	try {

		cout << "==============================================" << endl;
		cout << "=== LogBook ==================================" << endl;
		cout << "==============================================" << endl;

		LogBook log1;

		cout << "print empty LogBook: " << endl;
		log1.PrintLog(cout);
		cout << endl;

		cout << "add normal entries: " << endl;

		cout << boolalpha << log1.AddEntry("191028", 50) << endl;
		cout << boolalpha << log1.AddEntry("191105", 123) << endl;
		cout << boolalpha << log1.AddEntry("091004", 6) << endl;
		cout << boolalpha << log1.AddEntry("201010", 60) << endl;
		cout << endl;

		cout << "print log book: " << endl;
		log1.PrintLog(cout);
		cout << endl;

		cout << "add wrong entries: " << endl;

		cout << boolalpha << log1.AddEntry("", 44) << endl;
		cout << boolalpha << log1.AddEntry("1234", 8) << endl;
		cout << boolalpha << log1.AddEntry("11111111111", 6) << endl;
		cout << boolalpha << log1.AddEntry("asdf", 60) << endl << endl;


		cout << "print log book: " << endl;
		log1.PrintLog(cout);
		cout << endl;

		cout << "copy LogBook: " << endl;
		LogBook log2 = log1;

		cout << boolalpha << log2.AddEntry("121212", -24) << endl; //saved as size_t --> becomes huge number

		cout << "print LogBook2: " << endl;
		log2.PrintLog(cout);

		cout << "print LogBook to file 'output.txt': " << endl;

		ofstream outFile;
		outFile.open("logbook_output.txt");
		log1.PrintLog(outFile);
		outFile.close();
		cout << endl;

		cout << "print LogBook sum: " << endl;
		cout << "log1: " << log1.SumDistance() << " km" << endl;
		cout << endl;

		cout << "==============================================" << endl;
		cout << "=== Vehicles =================================" << endl;
		cout << "==============================================" << endl << endl;

		Car c1{ "Seat", "Ibiza", "FR-123AB", TFuel::DIESEL };
		Truck t1{ "Mercedes", "Actros", "L-456DS", TFuel::DIESEL };
		Motorcycle m1{ "Vespa", "GTS 300", "PE-2WER", TFuel::PETROL };

		cout << "add LogBook entries: " << endl;
		cout << boolalpha << c1.AddLogEntry("191005", 123) << endl;
		cout << boolalpha << c1.AddLogEntry("191012", 56) << endl;
		cout << boolalpha << c1.AddLogEntry("191013", 14) << endl;
		cout << boolalpha << c1.AddLogEntry("191020", 213) << endl;
		cout << boolalpha << c1.AddLogEntry("190810", 5) << endl;
		cout << boolalpha << c1.AddLogEntry("191015", 33) << endl << endl;
		c1.Print(cout);
		cout << endl;

		cout << "add LogBook entries: " << endl;
		cout << boolalpha << t1.AddLogEntry("180102", 567) << endl;
		cout << boolalpha << t1.AddLogEntry("180203", 788) << endl;
		cout << boolalpha << t1.AddLogEntry("180304", 123) << endl;
		cout << boolalpha << t1.AddLogEntry("180512", 89) << endl;
		cout << boolalpha << t1.AddLogEntry("111111", 585) << endl;
		cout << boolalpha << t1.AddLogEntry("120202", 975) << endl << endl;
		t1.Print(cout);

		cout << "add LogBook entries: " << endl;
		cout << boolalpha << m1.AddLogEntry("190523", 12) << endl;
		cout << boolalpha << m1.AddLogEntry("190524", 74) << endl;
		cout << boolalpha << m1.AddLogEntry("190602", 86) << endl;
		cout << boolalpha << m1.AddLogEntry("190707", 129) << endl;
		cout << boolalpha << m1.AddLogEntry("190916", 176) << endl;
		cout << boolalpha << m1.AddLogEntry("191112", 84) << endl << endl;
		m1.Print(cout);

		cout << "==============================================" << endl;
		cout << "=== Fleet ====================================" << endl;
		cout << "==============================================" << endl;

		Fleet f1;

		cout << "print empty fleet: " << endl;
		f1.Print(cout);
		cout << "remove something in empty fleet: " << endl;
		cout << f1.RemoveVehicle("asdf") << endl;

		Car c2{ "VW", "Passat" , "LL-621UV", TFuel::DIESEL };
		Car c3{ "Audi", "A8" , "L-8189F", TFuel::PETROL };
		Car c4{ "BMW", "i8" , "W-12345X", TFuel::ELECTRIC };
		Car c5{ "Lamborghini", "Huracan" , "FR-987DW", TFuel::PETROL };


		c2.AddLogEntry("190101", 50);
		c2.AddLogEntry("190210", 123);
		c2.AddLogEntry("010101", 101);

		c3.AddLogEntry("200101", 91);

		c4.AddLogEntry("191030", 519);
		c4.AddLogEntry("181010", 63);

		c5.AddLogEntry("101010", 24);
		c5.AddLogEntry("111111", 262);
		c5.AddLogEntry("121212", 623);
		c5.AddLogEntry("130313", 99);


		Truck t2{ "DAF", "XF" , "UU-456IS", TFuel::DIESEL };
		Truck t3{ "Scania", "V8" , "LI-67XFA", TFuel::DIESEL };


		t2.AddLogEntry("190808", 3521);
		t2.AddLogEntry("191010", 1524);

		Motorcycle m2{ "Ducati" , "998", "SR-273OA", TFuel::PETROL };
		Motorcycle m3{ "Aprilia" , "SX50", "LL-9XNM", TFuel::PETROL };
		Motorcycle m4{ "BMW" , "S1000RR", "PE-CHEF1", TFuel::PETROL };

		m2.AddLogEntry("180720", 51);

		m3.AddLogEntry("191102", 78);

		m4.AddLogEntry("150502", 314);
		m4.AddLogEntry("170114", 69);

		cout << endl << "total fleet distance: " << f1.GetTotalDistance() << endl;
		cout << "add vehicles: " << endl;



		cout << boolalpha << f1.AddVehicle(make_shared<Car>(c1)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Car>(c2)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Car>(c3)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Car>(c4)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Car>(c5)) << endl;

		cout << boolalpha << f1.AddVehicle(make_shared<Truck>(t1)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Truck>(t2)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared<Truck>(t3)) << endl;

		cout << boolalpha << f1.AddVehicle(make_shared <Motorcycle>(m1)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared <Motorcycle>(m2)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared <Motorcycle>(m3)) << endl;
		cout << boolalpha << f1.AddVehicle(make_shared <Motorcycle>(m4)) << endl;


		cout << endl << "print fleet: " << endl;
		f1.Print(cout);
		cout << "total fleet distance: " << f1.GetTotalDistance() << endl;

		cout << "print fleet to file: " << endl;
		ofstream outFileFleet;
		outFileFleet.open("fleet_output.txt");
		f1.Print(outFileFleet);
		outFileFleet.close();
		cout << endl;

		/////////////////////////////////////////////
		cout << endl << endl << endl << "assignment tests" << endl << endl;
		Fleet f2;

		f2.AddVehicle(make_shared<Car>(c2));
		f2.AddVehicle(make_shared<Truck>(t1));
		f2.AddVehicle(make_shared<Motorcycle>(m3));

		cout << endl << endl << "f2: " << endl << f2;

		Fleet f3;

		f3 = f2;

		f2.AddVehicle(make_shared<Car>(c4));

		cout << endl << endl << "f3: " << endl << f3;

		cout << endl << "remove vehicle: " << endl;
		cout << boolalpha << f2.RemoveVehicle("LL-621UV") << endl;

		cout << f2 << endl << endl << endl;

		cout << f3;

		cout << endl << "find vehicle: " << endl;

		Vehicle::SPtr veh = f2.Find("L-456DS");
		if (veh != nullptr) {
			veh->Print(cout);
		}
		cout << endl << "find not exisiting vehicle: " << endl;
		Vehicle::SPtr veh2 = f2.Find("asdf");
		if (veh2 != nullptr) {
			veh2->Print(cout);
		}
		else {
			cerr << "vehicle not found" << endl;
		}
	}
	catch (string const& ex) {
		cerr << ex << endl;
	}
	return 0;
}



