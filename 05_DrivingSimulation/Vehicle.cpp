#include "Vehicle.h"

void Vehicle::Attach(DisplayObserver::SPtr obs)
{
	if (obs == nullptr)
	{
		throw std::string("Nullpointer in Attach");
	}
	if (Contained(obs) == mObservers.cend())
	{
		mObservers.emplace_back(obs);
	}
}

void Vehicle::Detach(DisplayObserver::SPtr obs)
{
	if (obs == nullptr)
	{
		throw std::string("Nullpointer in Detach");
	}
	auto it = Contained(obs);
	if (it == mObservers.cend())
	{
		mObservers.erase(it);
	}
}

void Vehicle::Notify()
{
	for (auto const& observer : mObservers)
	{
		observer->Update();
	}
}

Vehicle::ObsCont::const_iterator Vehicle::Contained(DisplayObserver::SPtr const& obs) const
{
	return find(mObservers.cbegin(), mObservers.cend(), obs);
}
