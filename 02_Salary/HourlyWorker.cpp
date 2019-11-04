///////////////////////////////////////////////////////////////////////////
// Workfile :		HourlyWorker.cpp
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Implemenatation of class HourlyWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "HourlyWorker.h"

//Constant for error text
std::string const ERR_NEGATIVE = "has to be positive";


///////////////////////////////////////////////////////////////////////////
//CTor
///////////////////////////////////////////////////////////////////////////
HourlyWorker::HourlyWorker(std::string const& firstname, std::string const& name,
						   std::string const& shortname, std::string const& insurance,
						   size_t const& entryyear):
	Employee{firstname, name, shortname, insurance, entryyear, TWorker::HourlyWorker},
	mWagepH{0.0}, mHours{0.0}
{
}

///////////////////////////////////////////////////////////////////////////
//Setter & Getter
///////////////////////////////////////////////////////////////////////////
double HourlyWorker::GetSalary() const
{
	return mWagepH * mHours;
}

void HourlyWorker::SetWage(double wage)
{
	//wage can´t be below 0
	if (wage < 0)
	{
		std::cerr << "Wage " << ERR_NEGATIVE << std::endl;
	}
	else
	{
		mWagepH = wage;
	}
}

void HourlyWorker::SetHours(double hours)
{
	//You can´t work negative hours
	if (hours < 0)
	{
		std::cerr << "Hours " << ERR_NEGATIVE << std::endl;
	}
	else
	{
		mHours = hours;
	}
}


///////////////////////////////////////////////////////////////////////////
//Template Method to Print the Salary
///////////////////////////////////////////////////////////////////////////
void HourlyWorker::PrintSalary(std::ostream& ost) const
{
	ost << "Stundenlohn: " << mWagepH << Currency << std::endl
		<< "Stunden: " << mHours << std::endl
		<< "Gesamtgehalt: " << GetSalary() << Currency << std::endl;
}


