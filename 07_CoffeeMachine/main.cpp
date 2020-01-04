#include <iostream>

#include "Americano.h"
#include "Decaf.h"
#include "Espresso.h"
#include "Mocca.h"

#include "Milk.h"
#include "SoyMilk.h"
#include "Sugar.h"
#include "WhippedCream.h"

#include "CoffeePreparation.h"

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


	SoyMilk soy2{ make_shared<Decaf>(de) };
	Sugar sug2{ make_shared<Espresso>(es) };
	WhippedCream wh2{ make_shared<Mocca>(mo) };

	cout << soy2.GetDescription() << " " << soy2.GetCost() << endl;
	cout << sug2.GetDescription() << " " << sug2.GetCost() << endl;
	cout << wh2.GetDescription() << " " << wh2.GetCost() << endl;
	cout << endl << endl;


	CoffeePreparation prep;
	prep.Display(cout);
	prep.Prepare(make_shared<Americano>(am));
	prep.Prepare(make_shared<Decaf>(de));
	prep.Prepare(make_shared<Espresso>(es));
	prep.Prepare(make_shared<Mocca>(mo));
	prep.Prepare(make_shared<Milk>(milk));
	prep.Prepare(make_shared<SoyMilk>(soy));
	prep.Prepare(make_shared<Sugar>(sug));
	prep.Prepare(make_shared<WhippedCream>(wh));
	prep.Display(cout);
	cout << endl << endl;

	Coffee::SPtr mmm = prep.Finished();
	cout << mmm->GetDescription() << " " << mmm->GetCost() << endl;
	cout << endl << endl;
	prep.Finished();
	prep.Finished();
	prep.Finished();

	prep.Display(cout);
	cout << endl << endl;



	return 0;
}