///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			9-December-2019
// Description :	
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

	try {
		InputData(pCar);
	}
	catch (std::string ex){
		cerr << "error occured: " << ex << endl;
	}
	pCar->Detach(obs2);
	pCar->Detach(obs1);
}

void PrintNewCarBanner() {
	cout << "#######################################" << endl;
	cout << "########### N E W    C A R ############" << endl;
	cout << "#######################################" << endl;
}

int main()
{
	
	/*PrintNewCarBanner();

	//simple test run
	Drive();
	
	PrintNewCarBanner();

	//Empty File
	Drive("empty.txt");
	
	PrintNewCarBanner();
	
	//over maximum speed and long run
	Drive("Maserati.txt");
	*/
	PrintNewCarBanner();

	Drive("bullshit.txt");

	

	return 0;


}