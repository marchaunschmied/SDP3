///////////////////////////////////////////////////////////////////////////
// Workfile :		Employee.cpp
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Implemenatation of class Employee
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#include "Employee.h"

///////////////////////////////////////////////////////////////////////////
//Constants for configuration
///////////////////////////////////////////////////////////////////////////
size_t const SNameLen = 3;
size_t const iNrLen = 10;
std::string const HrLineS(15, '-');
std::string const HrLineL(40, '-');
std::string const Vers = "v1.0 Oktober 2019";
std::string const CURRENCY = " EUR";

///////////////////////////////////////////////////////////////////////////
//Setter & Getter
///////////////////////////////////////////////////////////////////////////
void Employee::SetName(std::string const& name)
{
	mName = name;
}

void Employee::SetSchortName(std::string const& sname)
{
	if (sname.size() == SNameLen)
	{
		mShortName = sname;
	}
	else
	{
		std::cerr << "Short name has to be " << SNameLen << " characters" << std::endl;
	}
	
}

TWorker Employee::GetType() const
{
	return mWorker;
}

///////////////////////////////////////////////////////////////////////////
//Print Method
//Throws an exception if stream is corrupted
///////////////////////////////////////////////////////////////////////////
void Employee::Print(std::ostream& ost)
{
	if (!ost.good())
	{
		throw std::string("Error in ostream");
	}
	ost << "Datenblatt: " << std::endl
		<< HrLineS << std::endl
		<< "Name: "						 << mFirstName << " " << mName << std::endl
		<< "Kuerzel: "					 << mShortName   << std::endl
		<< "Sozialversicherungsnummer: " << mInsuranceNr << std::endl
		<< "Mitarbeiterklasse: ";		 PrintType(ost);
	
	PrintSalary(ost);
	ost << HrLineL << std::endl << Vers << std::endl << HrLineL << std::endl;
}

///////////////////////////////////////////////////////////////////////////
//Protected CTor
///////////////////////////////////////////////////////////////////////////
Employee::Employee(std::string const& firstname, std::string const& name,
				   std::string const& shortname, std::string const& insurance,
				   size_t const& entryyear, TWorker const worker):
	mFirstName{firstname}, mName{name}, mEntryYear{entryyear},mWorker{worker}
{
	SetSchortName(shortname);
	if (CheckInsuranceNr(insurance)) { mInsuranceNr = insurance; }
}

///////////////////////////////////////////////////////////////////////////
//Checks if InsuranceNumber has the exact length
//and only consists of numbers
///////////////////////////////////////////////////////////////////////////
bool Employee::CheckInsuranceNr(std::string const& iNr) const
{

	if (iNr.size() != iNrLen)
	{
		std::cerr << "Insurance number has to be " << iNrLen << "characters" << std::endl;
		return false;
	}

	return std::all_of(iNr.cbegin(), iNr.cend(), std::isdigit);

}

///////////////////////////////////////////////////////////////////////////
//Prints the WorkerType
///////////////////////////////////////////////////////////////////////////
void Employee::PrintType(std::ostream& ost) const
{
	switch (mWorker)
	{
	case TWorker::PieceWorker:		ost << "PieceWorker" << std::endl;	    break;
	case TWorker::CommissionWorker: ost << "CommissionWorker" << std::endl; break;
	case TWorker::HourlyWorker:		ost << "HourlyWorker" << std::endl;		break;
	case TWorker::Boss:				ost << "Boss" << std::endl;				break;
	}
}

///////////////////////////////////////////////////////////////////////////
//Ostream manipu for the currency of the salary
///////////////////////////////////////////////////////////////////////////
std::ostream& Currency(std::ostream& ost)
{
	ost << CURRENCY;
	return ost;
}

