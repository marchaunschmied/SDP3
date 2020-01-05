///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Test
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

#include "vld.h"

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

string const line(80,'-');

int main()
{
	try
	{
		//----------------Test Nullpointers---------------------------------
		ICoffee::SPtr nCof = nullptr;
		cout << line << endl;
		cout << "Construct Ingredient with Nullpointer" << endl;
		cout << line << endl;
		try
		{
			Milk m{ nCof };
		}
		catch (string const& str)
		{
			cerr << str << endl;
		}

		try
		{
			WhippedCream w{ nCof };
		}
		catch (string const& str)
		{
			cerr << str << endl;
		}
		cout << endl << endl;

		cout << line << endl;
		cout << "Add Nullpointer to CoffeePreperation" << endl;
		cout << line << endl;
		try
		{
			CoffeePreparation cp;
			cp.Prepare(nCof);
		}
		catch (string const& str)
		{
			cerr << str << endl;
		}
		cout << endl << endl;

		//-------------------Test Coffees-----------------------------------
		cout << line << endl;
		cout << "Create Coffees" << endl;
		cout << line << endl;
		Americano am;
		Decaf de;
		Espresso es;
		Mocca mo;

		cout << am.GetDescription() << " " << am.GetCost() << endl;
		cout << de.GetDescription() << " " << de.GetCost() << endl;
		cout << es.GetDescription() << " " << es.GetCost() << endl;
		cout << mo.GetDescription() << " " << mo.GetCost() << endl;
		cout << endl << endl;


		//------------Test Coffees + Ingredients-----------------------------
		cout << line << endl;
		cout << "Add Ingredients" << endl;
		cout << line << endl;
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

		//-------------Test a huge amount of Ingredients-------------------------
		cout << line << endl;
		cout << "Add many Ingredients" << endl;
		cout << line << endl;
		ICoffee::SPtr dec = make_shared<Americano>();
		for (size_t i = 0; i < 150; ++i)
		{
			dec = make_shared<Milk>(Milk{ make_shared<Sugar>(Sugar{dec}) });
		}
		cout << dec->GetDescription() << " " << dec->GetCost() << endl;
		cout << endl << endl;

		//-------------------Coffee Preperation Empty-----------------------------
		cout << line << endl;
		cout << "Create CoffeePreparation" << endl;
		cout << line << endl;
		CoffeePreparation prep;
		prep.Display(cout);
		cout << endl << endl;

		//----------------Coffee Preparation Add----------------------------------
		cout << line << endl;
		cout << "Add Coffees to Coffe Preparation" << endl;
		cout << line << endl;
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

		//Test with file
		cout << "Print queue to File: Test.txt" << endl;
		ofstream file{ "Test.txt" };
		if (file.is_open())
		{
			prep.Display(file);
		}
		else
		{
			cerr << "ERROR: in open File" << endl;
		}
		file.close();
		if (file.is_open())
		{
			cerr << "ERROR: in closing File" << endl;
		}
		cout << endl << endl;

		//----------------Coffee Preparation Finish--------------------------------
		cout << line << endl;
		cout << "Finish 5 Coffees" << endl;
		cout << line << endl;
		for (size_t i = 0; i < 5; ++i)
		{
			ICoffee::SPtr finished = prep.Finished();
			if (finished == nullptr)
			{
				cout << "No Coffee to finish" << endl;
			}
			else
			{
				cout << "Finished: " << finished->GetDescription() << endl;
			}
		}

		cout << endl << "remaining queue:" << endl;
		prep.Display(cout);
		cout << endl << endl;

		cout << line << endl;
		cout << "Finish 10 more Coffees" << endl;
		cout << line << endl;
		for (size_t i = 0; i < 10; ++i)
		{
			ICoffee::SPtr finished = prep.Finished();
			if (finished == nullptr)
			{
				cout << "No Coffee to finish" << endl;
			}
			else
			{
				cout << "Finished: " << finished->GetDescription() << endl;
			}
		}
		cout << endl << "remaining queue:" << endl;
		prep.Display(cout);
		cout << endl << endl;


		return 0;
	}
	catch (exception const& ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}
	catch (std::string const& s)
	{
		cerr << s << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception" << endl;
		return 1;
	}
	
}