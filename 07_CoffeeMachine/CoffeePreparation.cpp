///////////////////////////////////////////////////////////////////////////
// Workfile :		CoffeePreparation.cpp
// Author :			Markus Riegler
// Date :			05-January-2019
// Description :	Implementation of class CoffeePreparation
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "CoffeePreparation.h"

///////////////////////////////////////////////////////////////////////////
//Adds a coffee which implements ICoffee to the queue
///////////////////////////////////////////////////////////////////////////
void CoffeePreparation::Prepare(ICoffee::SPtr coffee)
{
	//Check for nullpointer
	if (coffee == nullptr)
	{
		throw std::string("Nullpointer in CoffeePreparation::Prepare");
	}
	else
	{
		//Add it to the back of the queue
		mCoffeeQueue.emplace_back(coffee);
	}
}

///////////////////////////////////////////////////////////////////////////
//Prints declaration and Price of all Coffees in the queue
///////////////////////////////////////////////////////////////////////////
void CoffeePreparation::Display(std::ostream& os) const
{
	if (os.good())
	{
		for (auto coffee : mCoffeeQueue)
		{
			os << coffee->GetDescription() << " " 
			   << std::fixed << std::setprecision(2) << coffee->GetCost() 
			   << " " << CoffeePriceList::Currency << std::endl;
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//Removes the first Coffe in the Queue and returns it
///////////////////////////////////////////////////////////////////////////
ICoffee::SPtr CoffeePreparation::Finished()
{
	//Still Coffees in the queue
	if (mCoffeeQueue.empty())
	{
		//No
		return nullptr;
	}
	//Yes
	else
	{
		//Save the coffee temporarely
		ICoffee::SPtr tmp = mCoffeeQueue.front();
		//remove it from the container
		mCoffeeQueue.pop_front();
		//return it
		return tmp;
	}
}
