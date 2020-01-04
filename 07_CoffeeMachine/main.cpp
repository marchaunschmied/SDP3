#include <iostream>

#include "Americano.h"
#include "Decaf.h"
#include "Espresso.h"
#include "Mocca.h"

#include "Milk.h"
#include "SoyMilk.h"
#include "Sugar.h"
#include "WhippedCream.h"

using namespace std;

int main()
{
	Americano am;
	Decaf de;
	Espresso es;
	Mocca mo;

	cout << am.GetDescription() << " " << am.GetCost() << endl;
	cout << de.GetDescription() << " " << de.GetCost() << endl;
	cout << es.GetDescription() << " " << es.GetCost() << endl;
	cout << mo.GetDescription() << " " << mo.GetCost() << endl;
	cout << endl << endl;

	Milk milk{ make_shared<Americano>(am) };
	SoyMilk soy{ make_shared<Milk>(milk) };
	Sugar sug{ make_shared<SoyMilk>(soy) };
	WhippedCream wh{ make_shared<Sugar>(sug) };

	cout << milk.GetDescription() << " " << milk.GetCost() << endl;
	cout << soy.GetDescription() << " " << soy.GetCost() << endl;
	cout << sug.GetDescription() << " " << sug.GetCost() << endl;
	cout << wh.GetDescription() << " " << wh.GetCost() << endl;
	cout << endl << endl;
	return 0;
}