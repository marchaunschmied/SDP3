///////////////////////////////////////////////////////////////////////////
// Workfile :		CommissionWorker.cpp
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Implemenation of class CommissionWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "CommissionWorker.h"

std::string const ERR_NEGATIVE = "has to be positive";


///////////////////////////////////////////////////////////////////////////
//CTor
///////////////////////////////////////////////////////////////////////////
CommissionWorker::CommissionWorker(std::string const& firstname, std::string const& name,
								   std::string const& shortname, std::string const& insurance,
								   size_t const& entryyear):
	Employee{firstname, name, shortname, insurance, entryyear, TWorker::CommissionWorker},
	mBaseSalary{0.0}, mRate{0.0}, mPieces{0}
{
}

///////////////////////////////////////////////////////////////////////////
//Setter & Getter
///////////////////////////////////////////////////////////////////////////
double CommissionWorker::GetSalary() const
{
	return mBaseSalary + mRate * mPieces;
}

void CommissionWorker::SetSalary(double salary)
{
	//Salary can´t be below 0
	if (salary < 0)
	{
		std::cerr << "Salary " << ERR_NEGATIVE << std::endl;
	}
	else
	{
		mBaseSalary = salary;
	}
}

void CommissionWorker::SetPieces(size_t pieces)
{
	mPieces = pieces;
}

void CommissionWorker::SetRate(double rate)
{
	//Rate can´t be below 0
	if (rate < 0)
	{
		std::cerr << "Rate " << ERR_NEGATIVE << std::endl;
	}
	else
	{
		mRate = rate;
	}
}

///////////////////////////////////////////////////////////////////////////
//Template Method to Print the Salary
///////////////////////////////////////////////////////////////////////////
void CommissionWorker::PrintSalary(std::ostream& ost) const
{
	ost << "Grundgehalt: "	<< mBaseSalary		<< Currency << std::endl
		<< "Provision: "	<< mRate * mPieces	<< Currency << std::endl
		<< "Gesamtgehalt: " << GetSalary()		<< Currency << std::endl;
}


