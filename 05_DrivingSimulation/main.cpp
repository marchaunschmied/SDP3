///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			9-December-2019
// Description :	Testdriver for Driving Simulation: Simple Test,
//					Empty File, Invalid File, Reattach, Nullptr
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "Car.h"
#include "SpeedObserver.h"
#include "DistanceObserver.h"

using namespace std;


//simulates a car drive. Every 500ms a new speed value
//is read. If the car is standing still for 5 cycles (2.5s) 
//the simulation is terminated
void InputData(Car::SPtr pCar) {
	size_t zeroCnt = 0;
	while (zeroCnt < 5) {
		pCar->Process();
		try {
			if (pCar->GetCurrentSpeed() == 0) {
				zeroCnt++;
			}
			else {
				zeroCnt = 0;
			}
		}
		catch (std::string ex) {
			throw std::string{ ex };
		}
		Sleep(500);
	}
}


void Drive(string const& name = "") {
	try{
		Car::SPtr pCar;

		if (name == "") {
			pCar = make_shared<Car>();
		}
		else {
			pCar = make_shared<Car>(name);
		}
		SpeedObserver sp(pCar);
		DistanceObserver dp(pCar);

		DisplayObserver::SPtr obs1 = make_shared<SpeedObserver>(sp);
		DisplayObserver::SPtr obs2 = make_shared<DistanceObserver>(dp);

		pCar->Attach(obs1);
		pCar->Attach(obs2);

		InputData(pCar);

		pCar->Detach(obs2);
		pCar->Detach(obs1);
	}
	catch (std::string ex){
		cerr << "error occured: " << ex << endl;
	}

}


void DriveDetachReattachTest() {
	try {
		Car::SPtr pCar = make_shared<Car>();


		SpeedObserver sp(pCar);
		DistanceObserver dp(pCar);

		DisplayObserver::SPtr obs1 = make_shared<SpeedObserver>(sp);
		DisplayObserver::SPtr obs2 = make_shared<DistanceObserver>(dp);

		pCar->Attach(obs1);
		pCar->Attach(obs2);


		size_t zeroCnt = 0;
		size_t counter = 0;

		size_t const detachCnt = 5;
		size_t const reattachCnt = 10;

		while (zeroCnt < 5) {
			pCar->Process();
			try {
				if (pCar->GetCurrentSpeed() == 0) {
					zeroCnt++;
				}
				else {
					zeroCnt = 0;
				}
			}
			catch (std::string ex) {
				throw std::string{ ex };
			}

			if (counter == detachCnt) {
				pCar->Detach(obs1);
			}
			else if (counter == reattachCnt) {
				pCar->Attach(obs1);
			}

			Sleep(500);
			counter++;
		}
		pCar->Detach(obs2);
		pCar->Detach(obs1);
	}
	catch (std::string ex) {
		cerr << "error occured: " << ex << endl;
	}

}


void DriveNullPtrTest() {
	try {
		Car::SPtr pCar = make_shared<Car>();


		SpeedObserver sp(pCar);
		DistanceObserver dp(pCar);

		DisplayObserver::SPtr obs1 = make_shared<SpeedObserver>(sp);
		DisplayObserver::SPtr obs2 = nullptr;

		pCar->Attach(obs1);
		pCar->Attach(obs2);


		size_t zeroCnt = 0;

		while (zeroCnt < 5) {
			pCar->Process();
			try {
				if (pCar->GetCurrentSpeed() == 0) {
					zeroCnt++;
				}
				else {
					zeroCnt = 0;
				}
			}
			catch (std::string ex) {
				throw std::string{ ex };
			}
			Sleep(500);
		}
		pCar->Detach(obs2);
		pCar->Detach(obs1);
	}
	catch (std::string ex) {
		cerr << "error occured: " << ex << endl;
	}

}

void PrintNewCarBanner() {
	cout << "#######################################" << endl;
	cout << "########### N E W    C A R ############" << endl;
	cout << "#######################################" << endl;
}

int main()
{
	//simple test run
	PrintNewCarBanner();
	Drive();
	
	//Empty File
	PrintNewCarBanner();
	Drive("empty.txt");
	
	//invalid input file
	PrintNewCarBanner();
	Drive("bullshit.txt");

	//over maximum speed and long run
	PrintNewCarBanner();
	Drive("Maserati.txt");
	

	//no observer attached --> no output on console (nothing happens
	//until time of InputData is over)
	PrintNewCarBanner();
	Car::SPtr pCar = make_shared<Car>();
	try {
		InputData(pCar);
	}
	catch (std::string ex) {
		cerr << "error occured: " << ex << endl;
	}
	

	//detach and reattach during data fetching
	PrintNewCarBanner();
	DriveDetachReattachTest();

	//add nullptr observer
	PrintNewCarBanner();
	DriveNullPtrTest();

	return 0;


}