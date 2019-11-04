///////////////////////////////////////////////////////////////////////////
// Workfile :		PieceWorker.cpp
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Implemenatation of class PieceWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include "PieceWorker.h"

std::string const ERR_NEGATIVE = "has to be positive";

///////////////////////////////////////////////////////////////////////////
//CTor
///////////////////////////////////////////////////////////////////////////
PieceWorker::PieceWorker(std::string const& firstname, std::string const& name,
						 std::string const& shortname, std::string const& insurance,
						 size_t const& entryyear):
	Employee{firstname, name, shortname, insurance, entryyear, TWorker::PieceWorker},
	mRate{0.0}, mPieces{0}
{
}

///////////////////////////////////////////////////////////////////////////
//Setter & Getter
///////////////////////////////////////////////////////////////////////////
double PieceWorker::GetSalary() const
{
	return mRate * mPieces * 1.0;
}

size_t PieceWorker::GetPieces() const {
	return mPieces; 
}

void PieceWorker::SetPieces(size_t pieces)
{
	mPieces = pieces;
}

void PieceWorker::SetRate(double rate)
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
void PieceWorker::PrintSalary(std::ostream& ost) const
{
	ost << "Gehalt: " << GetSalary() << Currency << std::endl;
}
