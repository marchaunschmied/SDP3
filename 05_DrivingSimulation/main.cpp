#include <iostream>
#include "Car.h"
#include "SpeedObserver.h"
#include "DistanceObserver.h"

using namespace std;

int main()
{
	

	Car::SPtr pCar = make_shared<Car>("Maserati.txt");
	
	SpeedObserver sp(pCar);
	DistanceObserver dp(pCar);

	DisplayObserver::SPtr obs1 = make_shared<SpeedObserver>(sp);
	DisplayObserver::SPtr obs2 = make_shared<DistanceObserver>(dp);
	
	pCar->Attach(obs1);
	pCar->Attach(obs2);

	size_t zeroCnt = 0;
	while(zeroCnt < 5) {
		pCar->Process();
		if (pCar->GetCurrentSpeed() == 0) {
			zeroCnt++;
		}
		else {
			zeroCnt = 0;
		}
		Sleep(500);
	}
	pCar->Detach(obs2);
	pCar->Detach(obs1);
	
	return 0;


}