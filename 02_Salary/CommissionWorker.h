///////////////////////////////////////////////////////////////////////////
// Workfile :		CommissionWorker.h
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Header of class CommissionWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef COMMISSIONWORKER_H
#define COMMISSIONWORKER_H

#include "Employee.h"

class CommissionWorker : public Employee
{
public:
	CommissionWorker(std::string const& firstname, std::string const& name,
					 std::string const& shortname, std::string const& insurance,
					 size_t const& entryyear);
	//default DTor is enough
	~CommissionWorker() = default;

	//Setter & Getter
	double GetSalary() const override;
	size_t GetPieces() const;

	void SetSalary(double salary);
	void SetPieces(size_t pieces);
	void SetRate(double rate);


protected:
	//Template Method
	void PrintSalary(std::ostream& ost) const override;
	
private:
	double mBaseSalary;
	size_t mPieces;
	double mRate;
};

#endif // !COMMISSIONWORKER_H


