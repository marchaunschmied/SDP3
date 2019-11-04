///////////////////////////////////////////////////////////////////////////
// Workfile :		PieceWorker.h
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Header of class PieceWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"

class PieceWorker : public Employee
{
public:
	PieceWorker(std::string const& firstname, std::string const& name,
				std::string const& shortname, std::string const& insurance,
				size_t const& entryyear);
	//default DTor is enough
	~PieceWorker() = default;

	//Setter & Getter
	double GetSalary() const override;
	size_t GetPieces() const;
		

	void SetPieces(size_t pieces);
	void SetRate(double rate);

protected:
	void PrintSalary(std::ostream& ost) const override;

private:
	size_t mPieces;
	double mRate;
};

#endif // !PieceWorker_H



