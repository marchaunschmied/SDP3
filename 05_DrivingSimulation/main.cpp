#include <iostream>
#include "Car.h"
#include "SpeedObserver.h"
#include "DistanceObserver.h"

using namespace std;

int main()
{
	Car c;
	SpeedObserver sp;
	DistanceObserver dp;

	DisplayObserver::SPtr obs1 = make_shared<SpeedObserver>(sp);
	DisplayObserver::SPtr obs2 = make_shared<DistanceObserver>(dp);

	c.Attach(obs1);
	c.Attach(obs2);

	c.Process();
	c.Process();
	c.Process();
	c.Process();
	c.Process();
	c.Process();

	c.Detach(obs2);
	c.Detach(obs1);

	return 0;


}