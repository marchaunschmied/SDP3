#include "CoffeePreparation.h"

void CoffeePreparation::Prepare(Coffee::SPtr coffee)
{
	if (coffee == nullptr)
	{
		throw std::string("Nullpointer in CoffeePreparation::Prepare");
	}
	else
	{
		mCoffeeQueue.emplace_back(coffee);
	}
}

void CoffeePreparation::Display(std::ostream& os)
{
	if (os.good())
	{
		for (auto coffee : mCoffeeQueue)
		{
			os << coffee->GetDescription() << " " << std::fixed << std::setprecision(2) << coffee->GetCost() << " " << CoffeePriceList::Currency << std::endl;
		}
	}
}

Coffee::SPtr CoffeePreparation::Finished()
{
	if (mCoffeeQueue.empty())
	{
		return nullptr;
	}
	else
	{
		Coffee::SPtr tmp = mCoffeeQueue.front();
		mCoffeeQueue.pop_front();
		return tmp;
	}
}
